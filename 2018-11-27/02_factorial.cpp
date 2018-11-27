#include <iostream>

int factorial(int n) {
    if (n == 0) {
        return 1;
    }

    std::cout << "-> factorial(" << n << ")\n";

    int result = n * factorial(n - 1);

    std::cout << "<- factorial(" << n << ")\n";

    return result;
}

int main() {
    int c = factorial(3);

    std::cout << c;

    return 0;
}
