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
        } else if (n <= 6) {
            std::cout << 2 << std::endl;
        } else {
            const long long k = sqrt(n - 3) - 2;
            std::cout << 2 * (k + 1) << std::endl;
        }




    }

    return 0;
}
