#include <iostream>
#include <cmath>

int main() {
    long long n, k;
    std::cin >> n >> k;

    const long long x = (sqrt(8*(k + n) + 9) - 3) / 2;

    std::cout << n - x << std::endl;

    return 0;
}
