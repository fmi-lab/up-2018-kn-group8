#include <iostream>

using namespace std;

int main() {
    char c;
    int paren_counter = 0;

    while (true) {
        c = cin.get();

        if (c == '\n') {
            break;
        }

        if (c == '(') {
            paren_counter += 1;
        } else if (c == ')') {
            paren_counter -= 1;
        }

        if (paren_counter < 0) {
            break;
        }
    }

    if (paren_counter != 0) {
        cout << "Unbalanced!\n";
    } else {
        cout << "Balanced!\n";
    }

    return 0;
}
