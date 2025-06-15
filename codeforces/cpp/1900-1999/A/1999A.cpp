#include <iostream>
#include <vector>

int main() {
    int t, n;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        std::cin >> n;

        std::cout << n % 10 + n / 10 << std::endl;
    }
}
