#include <iostream>

using namespace std;

int input_substance() {
    cout << "Options: Water (1), Ethanol (2), Gold (3), Silver (4), Copper (5)\n";
    cout << "Please input substance: ";

    int substance;
    cin >> substance;

    return substance;
}

char input_unit() {
    cout << "Input unit: ";

    char unit;
    cin >> unit;

    return unit;
}

double melting_point_for_substance(int substance) {
    if (substance == 1) {
        return 0;
    }

    if (substance == 2) {
        return -114;
    }

    if (substance == 3) {
        return 1064;
    }

    if (substance == 4) {
        return 961.8;
    }

    if (substance == 5) {
        return 1085;
    }

    return 0;
}

double boiling_point_for_substance(int substance) {
    if (substance == 1) {
        return 100;
    }

    if (substance == 2) {
        return 78.37;
    }

    if (substance == 3) {
        return 2700;
    }

    if (substance == 4) {
        return 2162;
    }

    if (substance == 5) {
        return 2567;
    }

    return 0;
}

double convert_from_celsius(double temperature, char unit) {
    if (unit == 'C' || unit == 'c') {
        return temperature;
    }

    if (unit == 'F' || unit == 'f') {
        return (temperature - 32) / 1.8;
    }

    if (unit == 'K' || unit == 'k') {
        return temperature - 273.15;
    }

    cout << "Invalid unit!\n";
    return 0;
}

void print_temperatures(
    double melting_point,
    double boiling_point,
    char unit
) {
    cout << "Melting point: " << melting_point << unit << "\n";
    cout << "Boiling point: " << boiling_point << unit << "\n";
}

int main() {
    int substance = input_substance();
    char unit = input_unit();

    double melting_point = melting_point_for_substance(substance);
    double boiling_point = boiling_point_for_substance(substance);

    double melting_point_in_unit = convert_from_celsius(melting_point, unit);
    double boiling_point_in_unit = convert_from_celsius(boiling_point, unit);

    print_temperatures(
        melting_point_in_unit,
        boiling_point_in_unit,
        unit
    );

    return 0;
}
