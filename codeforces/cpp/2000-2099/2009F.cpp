#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        int n, q;
        std::cin >> n >> q;

        long long sum = 0;

        std::vector<long long> elems(n, 0);

        for (auto j = 0; j < n; j++) {
            std::cin >> elems[j];
            sum += elems[j];
        }

        long long l, r;

        for (auto j = 0; j < q; j++) {
            std::cin >> l >> r;

            long long rotate_left = l / n;
            long long shift_left = l % n - 1;

            long long rotate_right = r / n;
            long long shift_right = r % n;

            std::rotate(elems.begin(), elems.begin() + rotate_left, elems.end());
            long long sum_shift_left = 0;

            for (auto k = 0; k < shift_left; k++) {
                sum_shift_left += elems[k];
            }

            std::rotate(elems.rbegin(), elems.rbegin() + rotate_left, elems.rend());
            std::rotate(elems.begin(), elems.begin() + rotate_right, elems.end());
            long long sum_shift_right = 0;

            for (auto k = 0; k < shift_right; k++) {
                sum_shift_right += elems[k];
            }


            std::cout << (sum * rotate_right + sum_shift_right) - (sum * rotate_left + sum_shift_left) << std::endl;
        }

    }

    return 0;
}
