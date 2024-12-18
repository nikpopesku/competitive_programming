#include <iostream>

long long calc(int k, int m, int n) {
    long long s1 = k;
    long long s2 = k + n - 1;

    if (m > k) {
        s1 = (k + m) * m / 2;
    }


    if (m + 1 < k + n - 1) {
        s2 = (m + 1 + k + n - 1) * (k + n - 2 - m) / 2;
    }

    return std::abs(s1 - s2);
}

int main() {
    int t;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        int n, k;
        std::cin >> n >> k;

        int left = k;
        int right = k + n - 1;
        int m;

        while (left + 1 < right) {
            m = left + (right - left) / 2;

            if (calc(k, m, n) > calc(k, m-1, n)) {
                right = m;
            } else {
                left = m + 1;
            }
        }

        std::cout << std::abs(calc(k, left, n)) << std::endl;
    }

    return 0;
}
