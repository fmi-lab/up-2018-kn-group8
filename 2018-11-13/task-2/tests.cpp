#include <iostream>
#include <cstdlib>

double evaluate(char operators[], double numbers[], int length);

void print_expression(char operators[], double numbers[], int length) {
    // Попълнете този код
    std::cout << "CANNOT PRINT EXPRESSION";
}

void verify_result(double actual, double expected) {
    if (abs(actual - expected) < 0.000001) {
        std::cout << "OK";
    } else {
        std::cout << "Expected " << expected << ", got " << actual;
    }
}

void test_1() {
    // 5 3 *
    char operators[100] = { 0, 0, '*' };
    double numbers[100] = { 5, 3, 0 };
    int length = 3;

    print_expression(operators, numbers, length);
    std::cout << " ";

    double result = evaluate(operators, numbers, length);

    verify_result(result, 15);
}

void test_2() {
    // 4 1 - 3 /
    char operators[100] = { 0, 0, '-', 0, '/' };
    double numbers[100] = { 4, 1,  0,  3,  0  };
    int length = 5;

    print_expression(operators, numbers, length);
    std::cout << " ";

    double result = evaluate(operators, numbers, length);

    verify_result(result, 1);
}

void test_3() {
    // 5 7 * 1 11 - + 21 /
    char operators[100] = { 0, 0, '*', 0, 0, '-', '+', 0, '/' };
    double numbers[100] = { 5, 7,  0,  1, 11, 0,   0,  21, 0 };
    int length = 9;

    print_expression(operators, numbers, length);
    std::cout << " ";

    double result = evaluate(operators, numbers, length);

    verify_result(result, 1.1904761905);
}

void test_4() {
    // 42
    char operators[100] = { 0  };
    double numbers[100] = { 42 };
    int length = 1;

    print_expression(operators, numbers, length);
    std::cout << " ";

    double result = evaluate(operators, numbers, length);

    verify_result(result, 42);
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
