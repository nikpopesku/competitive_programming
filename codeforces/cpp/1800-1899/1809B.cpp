#include <iostream>
#include <cmath>

using namespace std::string_literals;

int main() {
    int t;
    long long n;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::cin >> n;
        long long left = sqrt(n) - 1;
        long long right = sqrt(n) + 1;

        while (left + 1 < right) {
            long long m = left + (right - left) / 2;

            if (m*m + 1 <= n) {
                left = m;
            } else {
                right = m - 1;
            }
        }

        std::cout << left << std::endl;
    }

    return 0;
}
