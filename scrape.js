function scrape() {
    var amount = document.getElementsByClassName("incomplete").length;
    var all_text = '';
    for (let i = 0; i < amount; i++) {
        all_text = all_text + document.getElementsByClassName("incomplete")[i].innerText;
    }
    console.log(all_text);
}