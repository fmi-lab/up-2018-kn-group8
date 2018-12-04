#include <iostream>
#include <cstring>

using namespace std;

const int ROWS = 5;
const int COLS = 5;
const int STR_SIZE = 100;

void spiral_walk(char matrix[ROWS][COLS][STR_SIZE], char result[]) {
    int startRow = 0, startCol = 0,
        endRow = ROWS - 1, endCol = COLS - 1,
        row = 0, col = 0;

    while (startRow <= endRow && startCol <= endCol) {
        strcat(result, matrix[row][col]);

        cout << row << ", " << col << "\n";

        if (row == startRow && col < endCol) {
            col++;

            if (col == endCol) {
                startRow++;
            }
        } else if (col == endCol && row < endRow) {
            row++;

            if (row == endRow) {
                endCol--;
            }
        } else if (row == endRow && col > startCol) {
            col--;

            if (col == startCol) {
                endRow--;
            }
        } else if (col == startCol && row > startRow) {
            row--;

            if (row == startRow) {
                startCol++;
            }
        }
    }

    strcat(result, matrix[row][col]);
}

int main() {
    char matrix[ROWS][COLS][STR_SIZE] = {
        {"aa", "bc", "c", "d", "e"},
        {"p", "qa", "r", "s", "f"},
        {"o", "x", "y", "t", "g"},
        {"n", "ww", "v", "u", "h"},
        {"m", "ll", "k", "j", "i"}
    };

    char result[ROWS * COLS * STR_SIZE + 1] = "";

    spiral_walk(matrix, result);

    cout << result << "\n";

    return 0;
}
