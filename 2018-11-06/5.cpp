#include <iostream>

using namespace std;

bool is_balanced(const char str[]) {
    char open[1000];
    int openN = 0;

    for (int i = 0; str[i]; i++) {
        if (
            str[i] == '(' ||
            str[i] == '[' ||
            str[i] == '{'
        ) {
            open[openN++] = str[i];
        }

        if (str[i] == ')') {
            if (openN == 0) {
                return false;
            }

            if (open[openN - 1] == '(') {
                openN--;
            } else {
                return false;
            }
        }

        if (str[i] == ']') {
            if (openN == 0) {
                return false;
            }

            if (open[openN - 1] == '[') {
                openN--;
            } else {
                return false;
            }
        }

        if (str[i] == '}') {
            if (openN == 0) {
                return false;
            }

            if (open[openN - 1] == '{') {
                openN--;
            } else {
                return false;
            }
        }
    }

    return openN == 0;
}

int main() {
    if (!is_balanced("(){}")) {
        cout << "NOT WORKING!!!1~!\n";
    }

    if (!is_balanced("{()[]}")) {
        cout << "NOT WORKING!!!1~! 2\n";
    }

    if (is_balanced("{([)[]]}")) {
        cout << "NOT WORKING!!!1~! 3\n";
    }

    return 0;
}
