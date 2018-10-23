#include <iostream>

void draw_n_times(char c, int times) {
    for (int i = 0; i < times; i++) {
        std::cout << c;
    }
}

void draw_tree(int corona_width, int thunk_height) {
    int half_width = corona_width / 2;

    for (int i = 0; i <= half_width; i++) {
        int num_stars = i;

        draw_n_times(' ', half_width - num_stars);
        draw_n_times('*', num_stars);
        draw_n_times('*', 1);
        draw_n_times('*', num_stars);
        draw_n_times(' ', half_width - num_stars);

        std::cout << "\n";
    }

    for (int i = 0; i < thunk_height; i++) {
        draw_n_times(' ', corona_width / 2 - 1);
        draw_n_times('=', 3);

        std::cout << "\n";
    }
}

int main() {
    int corona_width, thunk_height;

    std::cout << "Corona width: ";
    std::cin >> corona_width;

    std::cout << "Thunk height: ";
    std::cin >> thunk_height;

    draw_tree(corona_width, thunk_height);

    return 0;
}
