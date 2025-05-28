#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;

        if (a + b + c - std::min(std::min(a, b), c) >= 10) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}
