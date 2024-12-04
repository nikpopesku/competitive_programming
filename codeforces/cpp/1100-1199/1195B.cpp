#include <iostream>
#include <cmath>

int main() {
    int n, k;
    std::cin >> n >> k;

    const int x = (sqrt(8*(k + n) + 9) - 3) / 2;

    std::cout << n - x << std::endl;

    return 0;
}
