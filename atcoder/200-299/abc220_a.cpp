#include <iostream>

int main() {
    unsigned int a, b, c;
    std::cin >> a >> b >> c;

    unsigned int value = c;
    while (value <= a) {
        value += c;
    }

    std::cout << (a < value and value <= b ? value : -1) << std::endl;
}