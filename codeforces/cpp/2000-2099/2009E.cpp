#include <iostream>

long long calc(int k, int m, int n) {
    long long s1 = k;
    long long s2 = k + n - 1;

    if (m > k) {
        s1 = (k + m) * (m - k + 1) / 2;
    }


    if (m + 1 < k + n - 1) {
        s2 = (m + 1 + k + n - 1) * (k + n - 1 - m) / 2;
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
        int m = left;

        while (left + 1 < right) {
            m = left + (right - left - 1) / 2;

            if (calc(k, m, n) > calc(k, m+1, n)) {
                left = m;
            } else if (calc(k, m, n) < calc(k, m-1, n)) {
                right = m;
            } else {
                break;
            }
        }

        std::cout << std::abs(calc(k, m, n)) << std::endl;
    }

    return 0;
}
