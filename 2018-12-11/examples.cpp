#include <iostream>

using namespace std;

// int main() {
//     int a = 5;
//     int* b = &a;
//     int** c = &b;
//
//     *b = 10;
//     **c = 10;
//
//     // cout << b << " " << *b << " " << &b << "\n";
//     cout << **c << "\n";
//
//     return 0;
// }


// void swap(int* a, int* b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
//
// int main() {
//     int a = 5;
//     int b = 10;
//
//     swap(&a, &b);
//
//     cout << a << " " << b << "\n";
//
//     return 0;
// }


// int main() {
//     const int SIZE = 100;
//     int array[SIZE] = {0};
//     // int* array2 = array;
//
//     for (int i = 0; i < SIZE; i++) {
//         array[i] = i * i;
//     }
//
//     cout << array << " ";
//     // cout << *(int*)((long*)array + 1) << " ";
//     // cout << *(array + 2) << " ";
//     // cout << *(short*)array << " ";
//
//     // cout << array[1] << "\n";
//     // cout << *(array + 1) << "\n";
//     // cout << *(1 + array) << "\n";
//     cout << 1[array] << "\n";
// }


// void count_even_and_odd(
//     int* array,
//     int size,
//     int* even,
//     int* odd
// ) {
//     *even = 0;
//     *odd = 0;
//
//     for (int i = 0; i < size; i++) {
//         int number = array[i];
//         // int number = *(array + i);
//
//         if (number % 2 == 0) {
//             *even += 1;
//         } else {
//             *odd += 1;
//         }
//     }
// }

// int main() {
//     const int SIZE = 100;
//     int array[SIZE] = {0};
//
//     for (int i = 0; i < SIZE; i++) {
//         array[i] = i * i;
//     }
//
//     int even, odd;
//
//     count_even_and_odd(array, SIZE, &even, &odd);
//
//     cout << even << "\n";
//
//     return 0;
// }


int strlen(char* str) {
    int length = 0;

    while (*str != 0) {
        length++;
        str++;
    }

    return length;
}

char* strchr(char* str, char c) {
    while (*str != 0) {
        if (*str == c) {
            return str;
        }

        str++;
    }

    // return 0;
    // return NULL;
    return nullptr;
}

// #include <cstring>

int main() {
    char** str = {
        "Hello",
        "world"
    };

    // cout << strlen("Hello") << "\n";
    // cout << str << "\n";
    // cout << str + 1 << "\n";
    // cout << str + 2 << "\n";

    char* pointer = strchr(str, 'l');

    if (pointer) {
        cout << pointer << "\n";
    } else {
        cout << "Not found!\n";
    }

    // cout << strchr(str, 'a') << "\n";

    return 0;
}
