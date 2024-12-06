#include <iostream>
#include <cmath>

using namespace std::string_literals;

int main() {
    int t;
    long long n;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::cin >> n;
        long long left = 1;
        long long right = n;

        while (left <= right) {
            long long m = (n + 1) / 2;

            if (m*m + 1 < n) {
                left = m + 1;
            } else {
                right = m;
            }
        }

        std::cout << left << std::endl;
    }

    return 0;
}
