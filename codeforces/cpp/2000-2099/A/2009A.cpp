#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        int a, b;
        std::cin >> a >> b;
        std::cout << b - a << std::endl;
    }

    return 0;
}
