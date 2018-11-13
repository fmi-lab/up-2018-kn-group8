// Изтрийте този ред, ако използвате Visual Studio
#include "tests.cpp"

void swap(double array[], int i, int j) {
    double temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void sort(double array[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i; j < length; j++) {
            if (array[j] < array[i]) {
                swap(array, i, j);
            }
        }
    }
}
