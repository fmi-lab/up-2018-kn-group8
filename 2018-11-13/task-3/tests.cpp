#include <iostream>

bool is_magic_square(int matrix[][3]);

void test_1() {
    int matrix[3][3] = {
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8}
    };

    if (is_magic_square(matrix)) {
        std::cout << "OK";
    } else {
        std::cout << "NOT OK";
    }
}

void test_2() {
    int matrix[3][3] = {
        {2, 7, 6},
        {9, 1, 1},
        {4, 3, 8}
    };

    if (!is_magic_square(matrix)) {
        std::cout << "OK";
    } else {
        std::cout << "NOT OK";
    }
}

void test_3() {
    int matrix[3][3] = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    if (!is_magic_square(matrix)) {
        std::cout << "OK";
    } else {
        std::cout << "NOT OK";
    }
}

void test_4() {
    int matrix[3][3] = {
        {20, 70, 60},
        {90, 50, 10},
        {40, 30, 80}
    };

    if (!is_magic_square(matrix)) {
        std::cout << "OK";
    } else {
        std::cout << "NOT OK";
    }
}

int main() {
    std::cout << "Test 1: ";
    test_1();
    std::cout << "\n";

    std::cout << "Test 2: ";
    test_2();
    std::cout << "\n";

    std::cout << "Test 3: ";
    test_3();
    std::cout << "\n";

    std::cout << "Test 4: ";
    test_4();
    std::cout << "\n";
}
