#include <iostream>

int sum(int n) {
    if (n == 0) {
        return 0;
    }

    std::cout << "-> sum(" << n << ")\n";

    int result = n + sum(n - 1);

    std::cout << "<- sum(" << n << ")\n";

    return result;
}

int main() {
    int c = sum(3);

    std::cout << c;

    return 0;
}
