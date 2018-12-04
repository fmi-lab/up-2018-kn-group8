#include <iostream>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

void spiral_walk(char matrix[ROWS][COLS], char result[]) {
    int startRow = 0, startCol = 0,
        endRow = ROWS - 1, endCol = COLS - 1,
        row = 0, col = 0,
        resultIndex = 0;

    while (startRow <= endRow && startCol <= endCol) {
        result[resultIndex++] = matrix[row][col];

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

    result[resultIndex++] = matrix[row][col];
    result[resultIndex] = 0;
}

int main() {
    char matrix[ROWS][COLS] = {
        {'a', 'b', 'c', 'd', 'e'},
        {'p', 'q', 'r', 's', 'f'},
        {'o', 'x', 'y', 't', 'g'},
        {'n', 'w', 'v', 'u', 'h'},
        {'m', 'l', 'k', 'j', 'i'}
    };

    char result[ROWS * COLS + 1];

    spiral_walk(matrix, result);

    cout << result << "\n";

    return 0;
}
