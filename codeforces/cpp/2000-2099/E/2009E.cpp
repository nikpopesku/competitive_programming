#include <iostream>

long long calc(int k, long long m, int n) {
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

        long long left = k;
        long long right = k + n - 1;
        long long m = left;

        while (left + 1 < right) {
            m = (left + right) / 2;
            long long s0 = calc(k, m-1, n);
            long long s1 = calc(k, m, n);
            long long s2 = calc(k, m+1, n);

            if (s1 > s2) {
                left = m;
            } else if (s0 < s1) {
                right = m;
            } else {
                break;
            }
        }

        std::cout << std::abs(calc(k, m, n)) << std::endl;
    }

    return 0;
}
