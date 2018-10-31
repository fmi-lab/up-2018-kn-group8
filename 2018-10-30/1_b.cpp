#include <iostream>

using namespace std;

int input_numbers(int numbers[]) {
    int n;

    cout << "Number count: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    return n;
}

void count_numbers(int numbers[], int n, int counts[]) {
    for (int i = 0; i < n; i++) {
        // counts[i] = counts[i] + 1;
        // counts[i] += 1;
        counts[numbers[i]]++;
    }
}

int find_max_index(int counts[], int n) {
    int max_index = 0;

    for (int i = 0; i < n; i++) {
        if (counts[i] > counts[max_index]) {
            max_index = i;
        }
    }

    return max_index;
}

int main() {
    int numbers[1000];
    int n = input_numbers(numbers);

    int counts[1001] = { 0 };

    count_numbers(numbers, n, counts);

    int most_frequent_number = find_max_index(counts, n);

    cout << "Most frequent number: " << most_frequent_number << "\n";

    return 0;
}
