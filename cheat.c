#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

KeySym upper[] = {XK_A, XK_B, XK_C, XK_D, XK_E, XK_F, XK_G, XK_H, XK_I, XK_J, XK_K, XK_L, XK_M, XK_N, XK_O, XK_P, XK_Q, XK_R, XK_S, XK_T, XK_U, XK_V, XK_W, XK_X, XK_Y, XK_Z};
KeySym lower[] = {XK_a, XK_b, XK_c, XK_d, XK_e, XK_f, XK_g, XK_h, XK_i, XK_j, XK_k, XK_l, XK_m, XK_n, XK_o, XK_p, XK_q, XK_r, XK_s, XK_t, XK_u, XK_v, XK_w, XK_x, XK_y, XK_z};
char upper_lower(KeySym c) {
    for (int i = 0; i < 26; i++) {
        if (upper[i] == c) {
            return 0;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (lower[i] == c) {
            return 1;
        }
    }
}
void simulate(KeySym keysym, int modifiers) {
    Display *display = XOpenDisplay(NULL);
    KeyCode keycode = XKeysymToKeycode(display, keysym);
    if (modifiers == 0) {
        XTestFakeKeyEvent(display, keycode, True, 0);
        XFlush(display);

        XTestFakeKeyEvent(display, keycode, False, 0);
        XFlush(display);
    } else {
        KeyCode shiftKeyCode = XKeysymToKeycode(display, XK_Shift_L);

        XTestFakeKeyEvent(display, shiftKeyCode, True, 0);
        XFlush(display);

        XTestFakeKeyEvent(display, keycode, True, 0);
        XFlush(display);

        XTestFakeKeyEvent(display, keycode, False, 0);
        XFlush(display);

        XTestFakeKeyEvent(display, shiftKeyCode, False, 0);
        XFlush(display);
    }
    XCloseDisplay(display);
}
int main() {
    // delay time to start
    sleep(10);
    KeySym key_list[] = {};


    for (int i = 0; i < sizeof(key_list); ++i) {
        if (key_list[i] == XK_period) {
            simulate(XK_period, 0);
        } else {
            if (key_list[i] == XK_space) {
                simulate(XK_space, 0);
            } else {
                if (key_list[i] == XK_comma) {
                    simulate(XK_comma, 0);
                } else {
                    if (key_list[i] == XK_apostrophe) {
                        simulate(XK_apostrophe, 0);
                    } else {
                        if (upper_lower(key_list[i]) == 0) {
                            simulate(key_list[i], 1);
                        } else {
                            simulate(key_list[i], 0);
                        }
                    }
                }
            }
        }
    }
    return 0;
}