#include <iostream>
#include <cstdlib>

using namespace std;

const int WIDTH = 4, HEIGHT = 4;
const char UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd';

void move_to_right(int board[HEIGHT][WIDTH]) {
    for (int row = 0; row < HEIGHT; row++) {
        int free_cell_col = WIDTH - 1;

        for (int col = WIDTH - 1; col >= 0; col--) {
            if (board[row][col] != 0) {
                board[row][free_cell_col] = board[row][col];

                if (col != free_cell_col) {
                    board[row][col] = 0;
                }

                free_cell_col--;
            }
        }
    }
}

void merge_to_right(int board[HEIGHT][WIDTH]) {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = WIDTH - 1; col > 0; col--) {
            if (board[row][col] == board[row][col - 1]) {
                board[row][col] += board[row][col - 1];
                board[row][col - 1] = 0;
            }
        }
    }
}

void copy_board(int to[HEIGHT][WIDTH], int from[HEIGHT][WIDTH]) {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            to[row][col] = from[row][col];
        }
    }
}

void rotate_right(int board[HEIGHT][WIDTH]) {
    int rotated[HEIGHT][WIDTH] = {0};

    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            rotated[col][WIDTH - row - 1] = board[row][col];
        }
    }

    copy_board(board, rotated);
}

void spawn_new_number(int board[HEIGHT][WIDTH]) {
    int free_cell_count = 0;

    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            if (board[row][col] == 0) {
                free_cell_count++;
            }
        }
    }

    if (free_cell_count == 0) {
        return;
    }

    int spawn_index = rand() % 4;

    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            if (board[row][col] == 0 && spawn_index == 0) {
                board[row][col] = 2;
            }

            spawn_index--;
        }
    }
}

void make_move_to_right(int board[HEIGHT][WIDTH]) {
    move_to_right(board);
    merge_to_right(board);
    move_to_right(board);
    spawn_new_number(board);
}

void make_move(int board[HEIGHT][WIDTH], char direction) {
    if (direction == UP) {
        rotate_right(board);
        make_move_to_right(board);
        rotate_right(board);
        rotate_right(board);
        rotate_right(board);
    } else if (direction == LEFT) {
        rotate_right(board);
        rotate_right(board);
        make_move_to_right(board);
        rotate_right(board);
        rotate_right(board);
    } else if (direction == RIGHT) {
        make_move_to_right(board);
    } else {
        rotate_right(board);
        rotate_right(board);
        rotate_right(board);
        make_move_to_right(board);
        rotate_right(board);
    }
}

bool can_move(int board[HEIGHT][WIDTH]) {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            if (col > 0 && board[row][col] == board[row][col - 1]) {
                return true;
            }

            if (row > 0 && board[row][col] == board[row - 1][col]) {
                return true;
            }
        }
    }

    return false;
}

bool is_complete(int board[HEIGHT][WIDTH]) {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            if (board[row][col] == 2048) {
                return true;
            }
        }
    }

    return false;
}

void print_board(int board[HEIGHT][WIDTH]) {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            cout << board[row][col] << " ";
        }

        cout << "\n";
    }
}

int main() {
    srand(1234);

    int board[HEIGHT][WIDTH] = {
        {2, 2, 0, 0},
        {0, 0, 0, 2},
        {2, 0, 2, 0},
        {2, 2, 2, 2}
    };

    print_board(board);
    cout << "\n";

    while (can_move(board) && !is_complete(board)) {
        char direction;
        cout << "Direction (w a s d): ";
        cin >> direction;

        make_move(board, direction);
        print_board(board);
    }

    if (is_complete(board)) {
        cout << "You win!\n";
    } else if (!can_move(board)) {
        cout << "You lose!\n";
    }

    return 0;
}
