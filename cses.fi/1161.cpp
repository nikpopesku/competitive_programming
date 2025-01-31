#include <iostream>
#include <vector>

long long divide(int start, int end, long long x, std::vector<int> partial_sum) {
    if (start == end) return 0;

    long long min_delta = x;
    long long half = x / 2;
    int j = 0;

    int deduct = start > 0 ? partial_sum[start - 1] : 0;
    for (int i = start; i <= end; ++i) {
        if (std::abs(half - partial_sum[i] + deduct) < min_delta) {
            j = i;
            min_delta = std::abs(half - partial_sum[i] + deduct);
        }
    }

    return x + divide(start, j, partial_sum[j] - deduct, partial_sum) +
           divide(j + 1, end, partial_sum[end] - partial_sum[j], partial_sum);
}

int main() {
    int n;
    long long x;
    std::cin >> x >> n;
    std::vector<int> vc(n);
    std::vector<int> partial_sum(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> vc[i];
        partial_sum[i] = (i > 0 ? partial_sum[i - 1] : 0) + vc[i];
    }

    long long response = divide(0, n - 1, x, partial_sum);

    std::cout << response << std::endl;
}