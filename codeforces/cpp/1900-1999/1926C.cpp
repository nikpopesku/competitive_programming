#include <iostream>
#include <vector>

int main() {
    int t, n;
    std::cin >> t;
    int N = 2 * 10e5;
    std::vector digit_sum(N, 0);
    std::vector<long long> partial_sum(N, 0);

    for (auto i = 1; i <= N; i++) {
        int j = i;
        int sum = 0;
        while (j) {
            sum += j % 10;
            j /= 10;
        }

        digit_sum[i-1] = sum;
    }

    for (auto i = 1; i <= N; i++) {
        partial_sum[i] = partial_sum[i-1] + digit_sum[i-1];
    }

    for (auto i = 0; i < t; i++) {
        std::cin >> n;

        std::cout << partial_sum[n] << std::endl;
    }
}
