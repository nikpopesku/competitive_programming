#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    for (auto x = 0; x < t; x++) {
        int n, q;
        std::cin >> n >> q;

        std::vector<long long> elems(n), ps(1);

        for (auto &a : elems) {
            std::cin >> a;
            ps.push_back(ps.back() + a);
        }
        for (long long &r : elems) {
            ps.push_back(ps.back() + r);
        }

        long long l, r;

        for (auto y = 0; y < q; y++) {
            std::cin >> l >> r;

            l--; r--;
            long long i = l / n, j = r / n;
            l %= n; r %= n;

            std::cout << ps[n] * (j - i + 1) - (ps[i + l] - ps[i]) - (ps[j + n] - ps[j + r + 1]) << "\n";
        }

    }

    return 0;
}
