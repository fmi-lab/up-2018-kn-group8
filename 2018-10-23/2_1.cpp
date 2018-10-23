#include <iostream>

using namespace std;

int main() {
    char c;
    int paren_counter = 0;
    bool is_unbalanced = false;

    c = cin.get();

    while (!is_unbalanced && (c != '\n' || cin.eof())) {
        if (c == '(') {
            paren_counter += 1;
        } else if (c == ')') {
            paren_counter -= 1;
        }

        c = cin.get();

        if (paren_counter < 0) {
            is_unbalanced = true;
        }
    }

    if (paren_counter != 0) {
        cout << "Unbalanced!\n";
    } else {
        cout << "Balanced!\n";
    }

    return 0;
}
