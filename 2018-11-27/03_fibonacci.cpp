#include <iostream>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    std::cout << "-> fibonacci(" << n << ")\n";

    int result = fibonacci(n - 1) + fibonacci(n - 2);

    std::cout << "<- fibonacci(" << n << ")\n";

    return result;
}

int main() {
    int c = fibonacci(40);

    std::cout << c;

    return 0;
}
