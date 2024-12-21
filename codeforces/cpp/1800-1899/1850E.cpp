#include <iostream>
#include <cmath>
#include <climits>

int main() {
    int t;
    long long n;
    long long c, side;

    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::cin >> n >> c;

        long long sum = 0;

        for (int j = 0; j < n; j++) {
            std::cin >> side;

            sum += side;
            c -= side * side;

            long long left = 1;
            long long right = c;

            while (left <= right) {
                long long w = left + (right - left) / 2;

                double long expression = 4 * n * w * w + 4 * sum * w;

                if (expression == c) {
                    std::cout << w << std::endl;

                    break;
                } else if (expression > c) {
                    right = w - 1;
                } else {
                    left = w + 1;
                }
            }
        }
    }

    return 0;
}