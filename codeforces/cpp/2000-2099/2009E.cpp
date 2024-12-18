#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        int n, k;
        std::cin >> n >> k;

        long long sum = 0;
        long long left = k;
        long long right = k + n - 1;

        while (left <= right) {
            if (sum <= 0) {
                sum += left;
                left += 1;
            } else {
                sum -= right;
                right -= 1;
            }
        }

        std::cout << std::abs(sum) << std::endl;
    }

    return 0;
}
