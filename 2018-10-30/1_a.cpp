#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Number count: ";
    cin >> n;

    int numbers[1000];

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int counts[1001] = { 0 };

    for (int i = 0; i < n; i++) {
        // counts[i] = counts[i] + 1;
        // counts[i] += 1;
        counts[numbers[i]]++;
    }

    int max_index = 0;

    for (int i = 0; i < n; i++) {
        if (counts[i] > counts[max_index]) {
            max_index = i;
        }
    }

    cout << "Most frequent number: " << max_index << "\n";

    return 0;
}
