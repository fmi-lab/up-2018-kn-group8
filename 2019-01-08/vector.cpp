#include <iostream>

// Поддържат се следните функции:
//
// - new_vector - създава нов вектор с масив с големина (capacity) 1
// - v_resize - преоразмерява съществуващ вектор
// - v_push - добавя нов елемент в края на масива (и увеличава size)
// - v_pop - маха елемент от края на масива (намалява size) и го връща

struct Vector {
    // брой използвани елементи в масива
    int size;

    // големина на масива (максимален брой елементи)
    int capacity;

    // указател към масива
    int* array;
};

Vector new_vector() {
    Vector vector;

    vector.size = 0;
    vector.capacity = 1;

    int* array = (int*)malloc(sizeof(int));
    vector.array = array;

    return vector;
}

void v_resize(Vector& vector, int new_capacity) {
    std::cout << "Resized to " << new_capacity << "\n";

    // 1.
    int* new_array = (int*)malloc(sizeof(int) * new_capacity);
    int* old_array = vector.array;

    // 2.
    for (int i = 0; i < vector.size; i++) {
        new_array[i] = old_array[i];
    }

    // 3.
    free(old_array);

    // 4.
    vector.capacity = new_capacity;

    // 5.
    vector.array = new_array;
}

void v_push(Vector& vector, int element) {
    if (vector.size == vector.capacity) {
        v_resize(vector, vector.capacity * 2);
    }

    vector.array[vector.size] = element;
    vector.size++;
}

int v_pop(Vector& vector) {
    if (vector.size == 0) {
        // TODO: Wat do?
    }

    vector.size--;

    return vector.array[vector.size];
}

int main() {
    Vector vector = new_vector();

    for (int i = 0; i < 1000; i++) {
        v_push(vector, i * i);
    }

    int last = v_pop(vector);
    int second_to_last = v_pop(vector);

    std::cout << last << " " << second_to_last << "\n";

    return 0;
}
