#include <iostream>

int main() {
    int c = 0;
    char a[4] = { 0 };
    int b = 0;

    a[6] = 1;

    std::cout << &c << " " << &a << " " << &b << "\n";

    std::cout << c << " " << b << "\n";

    for (int i = 0; i < 4; i++) {
        std::cout << a[i] << "\n";
    }

    return 0;
}
