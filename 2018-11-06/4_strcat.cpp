#include <iostream>
#include <cstring>

using namespace std;

void our_strcat(char destination[], const char source[]) {
    int dest_i = 0;

    // dest_i = strlen(destination);
    while (destination[dest_i++]);

    int source_i = 0;
    while (source[source_i]) {
        destination[dest_i++] = source[source_i++];
    }
    // for (int source_i = 0; source[source_i] != 0; source_i++) {
    //     destination[dest_i++] = source[source_i];
    // }

    destination[dest_i] = 0;
}

int main() {
    char str[1000] = "Hello";
    our_strcat(str, " world");
    if (strcmp(str, "Hello world") != 0) {
        cout << "NOT WORKING!!!1~!\n";
    }

    char str1[1000] = "";
    our_strcat(str1, "world");
    if (strcmp(str1, "world") != 0) {
        cout << "NOT WORKING!!!1~! 2\n";
    }

    char str2[1000] = "Hello";
    our_strcat(str2, "");
    if (strcmp(str2, "Hello") != 0) {
        cout << "NOT WORKING!!!1~! 3\n";
    }

    char str3[1000] = "";
    our_strcat(str3, "");
    if (strcmp(str3, "") != 0) {
        cout << "NOT WORKING!!!1~! 4\n";
    }

    return 0;
}
