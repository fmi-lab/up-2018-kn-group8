#include <iostream>

using namespace std;

int main() {
    double degrees = 0;
    char unit = 0;
    char result_unit = 0;

    cout << "Enter temperature: ";
    cin >> degrees >> unit;

    if (unit > 96) {
        unit = unit - 32;
    }

    do {
        cout << "In which unit? (K, C, F): ";
        cin >> result_unit;

        if (result_unit > 96) {
            result_unit = result_unit - 32;
        }
    } while (unit == result_unit);

    double degrees_in_celsius = 0;

    if (unit == 'C' || unit == 'c') {
        degrees_in_celsius = degrees;
    } else if (unit == 'F' || unit == 'f') {
        degrees_in_celsius = (degrees - 32) / 1.8;
    } else if (unit == 'K' || unit == 'k') {
        degrees_in_celsius = degrees - 273.15;
    } else {
        cout << "Invalid unit!\n";
        return 1;
    }

    double result_degrees = 0;

    if (result_unit == 'C' || result_unit == 'c') {
        result_degrees = degrees_in_celsius;
    } else if (result_unit == 'F' || result_unit == 'f') {
        result_degrees = degrees_in_celsius * 1.8 + 32;
    } else if (result_unit == 'K' || result_unit == 'k') {
        result_degrees = degrees_in_celsius + 273.15;
    } else {
        cout << "Invalid result unit!\n";
        return 1;
    }

    cout << result_degrees << result_unit << "\n";

    return 0;
}
