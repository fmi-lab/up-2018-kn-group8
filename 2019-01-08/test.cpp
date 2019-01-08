struct Test {
    int a;
}

Test f1() {
    Test result;

    result.a = 2;

    return result;
}

Test* f2() {
    Test* result = (Test*)malloc(sizeof(Test));

    result.a = 5;

    return result;
}

void f3(Test test) {
    test.a = 5;
}

void f4(Test* test) {
    test->a = 5;
}

void f5(Test& test) {
    test.a = 5;
}

int main() {
    // Test* test = f2();
    // f1();

    // Test test;
    // test.a = 1;
    // f3(test);

    // Test test;
    // test.a = 1;
    // f4(&test);

    Test test;
    test.a = 1;
    f5(test);

    cout << test.a;
}
