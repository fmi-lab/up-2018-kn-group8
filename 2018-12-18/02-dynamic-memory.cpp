#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    cin >> n;

    // http://www.cplusplus.com/reference/cstdlib/malloc/
    int* numbers = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        cout << numbers[i];
    }

    // http://www.cplusplus.com/reference/cstdlib/free/
    free(numbers);

    return 0;
}
