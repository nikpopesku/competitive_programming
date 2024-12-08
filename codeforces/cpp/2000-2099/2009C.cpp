#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        int x, y, k;
        std::cin >> x >> y >> k;
        int steps_x = x / k;
        int steps_y = y / k;
        if (y % k) steps_y += 1;
        if (x % k) steps_x += 1;

        if (steps_y >= steps_x) {
            std::cout << steps_y * 2 << std::endl;
        } else {
            std::cout << 2 * steps_x - 1 << std::endl;
        }
    }

    return 0;
}
