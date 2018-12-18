#include <iostream>

// Един вектор е `void*` - указател към памет с три елемента:
//
// +----------+--------------+------------+
// | int size | int capacity | int* array |
// +----------+--------------+------------+
//
// - size - брой използвани елементи в масива
// - capacity - големина на масива (максимален брой елементи)
// - array - указател към масива
//
//
// Поддържат се следните функции:
//
// - new_vector - създава нов вектор с масив с големина (capacity) 1
// - v_get_size / v_set_size - взима или записва стойността на size
// - v_get_capacity / v_set_capacity - взима или записва стойността на capacity
// - v_get_array / v_set_array - взима или записва указателя към масива (int*)
// - v_resize - преоразмерява съществуващ вектор
// - v_push - добавя нов елемент в края на масива (и увеличава size)
// - v_pop - маха елемент от края на масива (намалява size) и го връща

int v_get_size(void* vector) {
    return *(int*)vector;
}

void v_set_size(void* vector, int new_size) {
    *(int*)vector = new_size;
}

int v_get_capacity(void* vector) {
    return *((int*)vector + 1);
}

void v_set_capacity(void* vector, int new_capacity) {
    *((int*)vector + 1) = new_capacity;
}

int* v_get_array(void* vector) {
    int* array_as_int = (int*)vector + 2;
    int** array_as_ptr_to_int = (int**)array_as_int;

    return *array_as_ptr_to_int;
}

void v_set_array(void* vector, int* new_array) {
    int* array_as_int = (int*)vector + 2;
    int** array_as_ptr_to_int = (int**)array_as_int;

    *array_as_ptr_to_int = new_array;
}

void* new_vector() {
    void* vector = malloc(sizeof(int) * 2 + sizeof(int*));

    v_set_size(vector, 0);
    v_set_capacity(vector, 1);

    int* array = (int*)malloc(sizeof(int));
    v_set_array(vector, array);

    return vector;
}

void v_resize(void* vector, int new_capacity) {
    std::cout << "Resized to " << new_capacity << "\n";

    // 1.
    int* new_array = (int*)malloc(sizeof(int) * new_capacity);
    int* old_array = v_get_array(vector);

    // 2.
    for (int i = 0; i < v_get_size(vector); i++) {
        new_array[i] = old_array[i];
    }

    // 3.
    free(old_array);

    // 4.
    v_set_capacity(vector, new_capacity);

    // 5.
    v_set_array(vector, new_array);
}

void v_push(void* vector, int element) {
    if (v_get_size(vector) == v_get_capacity(vector)) {
        v_resize(vector, v_get_capacity(vector) * 2);
    }

    v_get_array(vector)[v_get_size(vector)] = element;
    v_set_size(vector, v_get_size(vector) + 1);
}

int v_pop(void* vector) {
    if (v_get_size(vector) == 0) {
        // TODO: Wat do?
    }

    v_set_size(vector, v_get_size(vector) - 1);

    return v_get_array(vector)[v_get_size(vector)];
}

int main() {
    void* vector = new_vector();

    for (int i = 0; i < 1000; i++) {
        v_push(vector, i * i);
    }

    int last = v_pop(vector);
    int second_to_last = v_pop(vector);

    std::cout << last << " " << second_to_last << "\n";

    return 0;
}
