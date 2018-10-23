#include <iostream>

using namespace std;

int main() {
    char c;
    int chars = 0, words = 0, lines = 0;
    bool had_symbol = false;

    while (true) {
        c = cin.get();

        if (cin.eof()) {
            break;
        }

        chars++;

        switch (c) {
        case ' ':
            if (had_symbol) {
                words++;
            }

            had_symbol = false;
            break;

        case '\n':
            if (had_symbol) {
                words++;
            }

            lines++;
            had_symbol = false;
            break;

        default:
            had_symbol = true;
        }
    }

    cout << "Chars: " << chars << "\n";
    cout << "Words: " << words << "\n";
    cout << "Lines: " << lines << "\n";

    return 0;
}
