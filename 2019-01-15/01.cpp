#include <iostream>

using namespace std;

struct Point {
    int row;
    int col;
};

Point findStart(
    char labyrinth[100][100],
    int rows, int cols
) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (labyrinth[row][col] == 'A') {
                Point point;
                point.row = row;
                point.col = col;

                return point;
            }
        }
    }

    Point point;
    point.row = -1;
    point.col = -1;

    return point;
}

void printPoint(Point point) {
    cout << "(" << point.row << ", " << point.col << ")";
}

int calculatePathLengthRecursively(
    char labyrinth[100][100],
    bool visited[100][100],
    int rows, int cols,
    int row, int col
) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        return -1;
    }

    if (visited[row][col]) {
        return -1;
    }

    if (labyrinth[row][col] == '=') {
        return -1;
    }

    if (labyrinth[row][col] == 'B') {
        return 0;
    }

    visited[row][col] = true;

    int pathLengthUp = calculatePathLengthRecursively(labyrinth, visited, rows, cols, row - 1, col);
    if (pathLengthUp != -1) {
        return pathLengthUp + 1;
    }

    int pathLengthDown = calculatePathLengthRecursively(labyrinth, visited, rows, cols, row + 1, col);
    if (pathLengthDown != -1) {
        return pathLengthDown + 1;
    }

    int pathLengthLeft = calculatePathLengthRecursively(labyrinth, visited, rows, cols, row, col - 1);
    if (pathLengthLeft != -1) {
        return pathLengthLeft + 1;
    }

    int pathLengthRight = calculatePathLengthRecursively(labyrinth, visited, rows, cols, row, col + 1);
    if (pathLengthRight != -1) {
        return pathLengthRight + 1;
    }

    return -1;
}

int pathLength(
    char labyrinth[100][100],
    int rows, int cols
) {
    bool visited[100][100] = {false};
    Point start = findStart(labyrinth, rows, cols);

    return calculatePathLengthRecursively(labyrinth, visited, rows, cols, start.row, start.col);
}

int main() {
    char labyrinth[100][100] = {
        {' ', ' ', '=', ' ', ' ', ' ', ' '},
        {'=', ' ', ' ', ' ', '=', ' ', ' '},
        {'=', '=', ' ', '=', '=', ' ', ' '},
        {' ', ' ', 'A', '=', ' ', '=', ' '},
        {' ', '=', '=', '=', 'B', '=', '='},
        {' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    cout << "Path length: " << pathLength(labyrinth, 6, 7) << "\n";

    return 0;
}
