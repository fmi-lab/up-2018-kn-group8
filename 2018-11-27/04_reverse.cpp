#include <iostream>

using namespace std;

void print_reverse() {
    char c;
    c = cin.get();

    if (c == '\n') {
        return;
    }

    // ->

    print_reverse();

    cout << c;
    // <-
}

int main() {
    print_reverse();

    return 0;
}
