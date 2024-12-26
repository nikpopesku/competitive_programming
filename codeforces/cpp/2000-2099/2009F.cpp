#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        int n, q;
        std::cin >> n >> q;

        std::vector<long long> elems(n, 0);
        std::vector<long long> partial_sum(n * n + 1, 0);
        int input;

        for (auto j = 0; j < n; j++) {
            std::cin >> elems[j];
        }

        for (auto j = 0; j < n; j++) {
            std::rotate(elems.begin(), elems.begin() + j % n, elems.end());

            for (auto k = 1; k < n; k++) {
                partial_sum[k] = partial_sum[k-1] + elems[k-1];
            }
        }

        long long l, r;

        for (auto j = 0; j < q; j++) {
            std::cin >> l >> r;

            std::cout << partial_sum[r] - partial_sum[l] << std::endl;
        }

    }

    return 0;
}
