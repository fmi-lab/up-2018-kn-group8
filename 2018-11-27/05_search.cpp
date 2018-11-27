#include <iostream>

using namespace std;

const int N = 1000000;

int search(
    int numbers[],
    int startIndex,
    int endIndex,
    int number
) {
    cout << "start: " << startIndex << ", end: " << endIndex << "\n";

    if (startIndex > endIndex) {
        return -1;
    }

    int length = endIndex - startIndex;
    int midIndex = startIndex + length / 2;

    if (numbers[midIndex] == number) {
        return midIndex;
    } else if (numbers[midIndex] > number) {
        return search(numbers, startIndex, midIndex - 1, number);
    } else {
        return search(numbers, midIndex + 1, endIndex, number);
    }
}

int main() {
    int numbers[N] = {0};

    for (int i = 0; i < N; i++) {
        numbers[i] = i + 10;
    }

    cout << search(numbers, 0, N - 1, 623481) << "\n";

    return 0;
}
