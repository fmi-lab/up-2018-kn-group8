#include <iostream>

using namespace std;

int main() {
    double degrees;
    char unit;

    cout << "Enter temperature: ";
    cin >> degrees >> unit;

    if (unit == 'C' || unit == 'c') {
        cout << degrees << "C\n";
    } else if (unit == 'F' || unit == 'f') {
        cout << (degrees - 32) / 1.8 << "C\n";
    } else if (unit == 'K' || unit == 'k') {
        cout << degrees - 273.15 << "C\n";
    } else {
        cout << "Invalid unit!\n";
        return 1;
    }

    return 0;
}
