#include <iostream>
#include <cmath>

using namespace std::string_literals;

int main() {
    int t;
    long long n;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::cin >> n;

        if (n == 1)  {
            std::cout << 0 << std::endl;
        } else if (n <= 4) {
            std::cout << 1 << std::endl;
        } else if (n <= 10) {
            std::cout << 3 << std::endl;
        } else {
            const long long k = (sqrt(9 + 4 * n) - 5) / 2;
            std::cout << k + 3 << std::endl;
        }




    }

    return 0;
}
