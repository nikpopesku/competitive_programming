#include <iostream>

int main() {
    unsigned int n;
    std::cin >> n;
    int response = 0, value = 0;

    for (auto i = 0; i < n; i++) {
        std::cin >> value;

        if (value > 10) response += value - 10;
    }

    std::cout << response << std::endl;
}