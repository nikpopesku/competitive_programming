#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        int best_a = 0;
        int best_b = 0;

        for (auto j = 0; j < n; j++) {
            int a, b;
            std::cin >> a >> b;

            if (a <= 10 and b > best_b) {
                best_b = b;
                best_a = j + 1;
            }
        }

        std::cout << best_a << std::endl;
    }

    return 0;
}
