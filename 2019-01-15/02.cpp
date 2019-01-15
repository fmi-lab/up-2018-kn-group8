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
    Point path[10000],
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
        path[0].row = row;
        path[0].col = col;

        return 1;
    }

    visited[row][col] = true;

    int pathLengthUp = calculatePathLengthRecursively(
        labyrinth,
        visited,
        path,
        rows, cols,
        row - 1, col
    );
    if (pathLengthUp != -1) {
        path[pathLengthUp].row = row;
        path[pathLengthUp].col = col;

        return pathLengthUp + 1;
    }

    int pathLengthDown = calculatePathLengthRecursively(
        labyrinth,
        visited,
        path,
        rows, cols,
        row + 1, col
    );
    if (pathLengthDown != -1) {
        path[pathLengthDown].row = row;
        path[pathLengthDown].col = col;

        return pathLengthDown + 1;
    }

    int pathLengthLeft = calculatePathLengthRecursively(
        labyrinth,
        visited,
        path,
        rows, cols,
        row, col - 1
    );
    if (pathLengthLeft != -1) {
        path[pathLengthLeft].row = row;
        path[pathLengthLeft].col = col;

        return pathLengthLeft + 1;
    }

    int pathLengthRight = calculatePathLengthRecursively(
        labyrinth,
        visited,
        path,
        rows, cols,
        row, col + 1
    );
    if (pathLengthRight != -1) {
        path[pathLengthRight].row = row;
        path[pathLengthRight].col = col;

        return pathLengthRight + 1;
    }

    return -1;
}

int pathLength(
    char labyrinth[100][100],
    Point path[10000],
    int rows, int cols
) {
    bool visited[100][100] = {false};
    Point start = findStart(labyrinth, rows, cols);

    return calculatePathLengthRecursively(
        labyrinth, visited, path, rows, cols, start.row, start.col
    );
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

    Point path[10000];
    int length = pathLength(labyrinth, path, 6, 7);

    cout << "Path length: " << length << "\n";

    for (int i = length - 1; i >= 0; i--) {
        printPoint(path[i]);

        if (i > 0) {
            cout << " -> ";
        }
    }

    cout << "\n";

    return 0;
}
