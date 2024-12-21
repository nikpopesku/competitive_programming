#include <iostream>
#include <cmath>
#include <vector>

int main() {
    int t;
    long long n;
    long long c;

    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::cin >> n >> c;
        std::vector<long long> sides (n);
        for (int j = 0; j < n; j++) std::cin >> sides[j];

        long long left = 1;
        long long right = 1e9;


        while (left <= right) {
            long long w = left + (right - left) / 2;
            long long sum = 0;

            for (int j = 0; j < n; j++) {
                sum += (sides[j] + 2 * w) * (sides[j] + 2 * w);

                if (sum > c) break;
            }


            if (sum == c) {
                std::cout << w << std::endl;
                break;
            } else if (sum > c) {
                right = w - 1;
            } else {
                left = w + 1;
            }
        }
    }

    return 0;
}