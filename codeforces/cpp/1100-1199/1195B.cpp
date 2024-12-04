#include <iostream>
#include <cmath>

int main() {
    int n, k;
    std::cin >> n >> k;

    const int x = (sqrt(8*k + 1) - 1) / 2;
    const int response = n - x;

    std::cout << response << std::endl;

    return 0;
}
