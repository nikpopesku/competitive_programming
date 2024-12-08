#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        int x, y, k;
        std::cin >> x >> y >> k;

        if (y >= x) {
            int steps = y / k;
            if (y % k) steps += 1;
            std::cout << steps * 2 << std::endl;
        } else {
            int steps = x / k;
            if (x % k) steps += 1;
            std::cout << 2 * steps - 1 << std::endl;
        }
    }

    return 0;
}
