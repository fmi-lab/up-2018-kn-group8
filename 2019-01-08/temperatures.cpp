#include <iostream>
#include <cstring>

using namespace std;

struct Material {
    char name[100];
    double boilingPoint;
    double meltingPoint;
};

int main() {
    Material materials[1000];
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        Material mat;

        cin >> mat.name;
        cin >> mat.meltingPoint;
        cin >> mat.boilingPoint;

        materials[i] = mat;
    }

    char name[100];
    cin >> name;

    for (int i = 0; i < n; i++) {
        if (strcmp(name, materials[i].name) == 0) {
            cout << materials[i].meltingPoint << " " << materials[i].boilingPoint << "\n";
            break;
        }
    }

    // for (int i = 0; i < 2; i++) {
    //     cout << materials[i].name << " " << materials[i].meltingPoint << " " << materials[i].boilingPoint << "\n";
    // }
}
