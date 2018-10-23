#include <iostream>

using namespace std;

int main() {
    char c;
    int chars = 0, words = 0, lines = 0;
    bool had_symbol = false;

    while (true) {
        c = cin.get();

        if (c == EOF) {
            break;
        }

        chars++;

        if (c == ' ' && had_symbol) {
            words++;
            had_symbol = false;
        } else if (c == '\n') {
            if (had_symbol) {
                words++;
            }

            lines++;
            had_symbol = false;
        } else if (c != ' ' && c != '\n') {
            had_symbol = true;
        }
    }

    cout << "Chars: " << chars << "\n";
    cout << "Words: " << words << "\n";
    cout << "Lines: " << lines << "\n";

    return 0;
}
