bool kurungSeimbang(const string& ekspresi) {
    Stack sKurung;
    inisialisasi(sKurung);

    for (char c : ekspresi) {
        if (c == '(' || c == '[' || c == '{') {
            push(sKurung, c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty(sKurung)) {
                clear(sKurung);
                return false;
            }

            int temp;
            pop(sKurung, temp);
            char buka = temp;

            if ((c == ')' && buka != '(') ||
                (c == ']' && buka != '[') ||
                (c == '}' && buka != '{')) {
                clear(sKurung);
                return false;
            }
        }
    }

    bool seimbang = isEmpty(sKurung);
    clear(sKurung);
    return seimbang;
}