#include <iostream>
#include <vector>

int main() {
    unsigned int a, b;
    std::cin >> a >> b;

    std::cout << ((b - a == 1 || b - a == 9) ? "Yes" : "No") << std::endl;
}