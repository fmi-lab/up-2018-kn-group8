#include <iostream>

void sort(double array[], int length);

void print_array(double array[], int length) {
    std::cout << "[";

    for (int i = 0; i < length; i++) {
        std::cout << array[i];

        if (i != length - 1) {
            std::cout << ", ";
        }
    }

    std::cout << "]";
}

bool compare_arrays(double expected[], double actual[], int length) {
    for (int i = 0; i < length; i++) {
        if (expected[i] != actual[i]) {
            std::cout << "Expected ";
            print_array(expected, length);
            std::cout << " but got ";
            print_array(actual, length);

            return false;
        }
    }

    return true;
}

void test_1() {
    double expected[100] = { 1, 2, 3, 4, 5 };
    double actual[100] = { 1, 2, 3, 4, 5 };

    sort(actual, 5);

    if (compare_arrays(expected, actual, 5)) {
        std::cout << "OK";
    }
}

void test_2() {
    double expected[100] = { 1, 2, 3, 4, 5 };
    double actual[100] = { 5, 3, 2, 4, 1 };

    sort(actual, 5);

    if (compare_arrays(expected, actual, 5)) {
        std::cout << "OK";
    }
}

void test_3() {
    double expected[100] = { 1, 2, 3, 4, 5 };
    double actual[100] = { 5, 3, 2, 4, 1 };

    sort(actual, 0);

    if (compare_arrays(expected, actual, 0)) {
        std::cout << "OK";
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
}
