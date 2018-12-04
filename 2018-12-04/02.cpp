#include <iostream>

using namespace std;

const int MAX_STR_SIZE = 100;

int add_word(
    char word[],
    char words[][MAX_STR_SIZE],
    int word_counts[],
    int words_length
) {
    for (int i = 0; i < words_length; i++) {
        if (strcmp(words[i], word) == 0) {
            word_counts[i]++;
            return words_length;
        }
    }

    strcpy(words[words_length], word);
    word_counts[words_length] = 1;

    return words_length + 1;
}

void sort_words(
    char words[][MAX_STR_SIZE],
    int word_counts[],
    int words_length
) {
    // TODO
}

int sorted_word_count(
    char input[],
    char words[][MAX_STR_SIZE],
    int word_counts[]
) {
    int words_length = 0;
    int length = strlen(input);
    bool in_word = false;
    char current_word[MAX_STR_SIZE] = "";
    int index_in_word = 0;

    for (int i = 0; i < length; i++) {
        char c = input[i];

        if (c >= 'a' && c <= 'z') {
            in_word = true;
            current_word[index_in_word++] = c;
        } else if (in_word) {
            in_word = false;
            current_word[index_in_word++] = 0;

            words_length = add_word(
                current_word,
                words,
                word_counts,
                words_length
            );

            index_in_word = 0;
        }
    }

    sort_words(words, word_counts, words_length);

    return words_length;
}

int main() {
    char input[1000] = "how much wood would a woodchuck chuck if a woodchuck could chuck wood? as much wood as a woodchuck would chuck if a woodchuck could chuck wood.";

    char words[1000][MAX_STR_SIZE];
    int word_counts[1000];

    int words_length = sorted_word_count(input, words, word_counts);

    for (int i = 0; i < words_length; i++) {
        cout << words[i] << " " << word_counts[i] << "\n";
    }

    return 0;
}
