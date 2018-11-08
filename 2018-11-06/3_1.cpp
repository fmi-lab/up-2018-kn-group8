#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Sequence length: ";
    cin >> n;

    int sequence[1000];

    cout << "Sequence: ";
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    int maxLength = 1,
        maxIndex = 0,
        currentLength = 1,
        currentIndex = 0;

    for (int i = 1; i < n; i++) {
            if (currentLength > maxLength) {
                maxLength = currentLength;
                maxIndex = currentIndex;
            }

            currentIndex = i;
            currentLength = 1;
        } else {
            currentLength++;
        }
    }

    cout << "Result: ";

    for (int i = maxIndex; i < maxIndex + maxLength; i++) {
        cout << sequence[i] << " ";
    }

    cout << "\n";
}
