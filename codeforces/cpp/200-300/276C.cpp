#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    // Read the initial array
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // Use a difference array to store frequencies
    // The size is n+1 to handle the r+1 decrement safely
    std::vector<long long> counts(n + 1, 0);
    for (int i = 0; i < q; ++i) {
        int l, r;
        std::cin >> l >> r;
        // 1-based to 0-based index conversion
        counts[l - 1]++;
        if (r < n) {
            counts[r]--;
        }
    }

    // Calculate prefix sums to get the actual frequency of each index
    for (int i = 1; i < n; ++i) {
        counts[i] += counts[i - 1];
    }

    // Sort the original numbers and the frequencies
    std::sort(a.begin(), a.end());
    // We only need the first n frequencies, so we sort counts up to n
    std::sort(counts.begin(), counts.begin() + n);

    // Calculate the maximum sum by pairing the largest numbers with the highest frequencies
    long long max_sum = 0;
    for (int i = 0; i < n; ++i) {
        max_sum += a[i] * counts[i];
    }

    std::cout << max_sum << std::endl;

    return 0;
}