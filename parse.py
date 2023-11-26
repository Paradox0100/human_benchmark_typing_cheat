my_string = ""
list = []
for i in range(len(my_string)):
	list.append(my_string[i])
big_var = ''
for z in range(len(my_string)):
    if (list[z] == "."):
          list[z] = "period"
    if (list[z] == ","):
          list[z] = "comma"
    if (list[z] == " "):
          list[z] = "space"
    if (list[z] == "'"):
          list[z] = "apostrophe"
    if (list[z] == "-"):
          list[z] = "minus"
    if (list[z] == "!"):
          list[z] = "exclam"
    big_var = big_var + 'XK_' + list[z] + ', '
print(big_var)