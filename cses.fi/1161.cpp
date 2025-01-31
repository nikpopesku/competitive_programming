#include <iostream>
#include <vector>

int divide(int start, int end, int x, std::vector<int> partial_sum) {
    if (start == end) return 0;

    int min_delta = x;
    int half = x / 2;
    int response = 0;
    int j = 0;

    for (int i = start; i <= end; ++i) {
        if (std::abs(half - partial_sum[i]) < min_delta) {
            j = i;
            min_delta = std::abs(half - partial_sum[i]);
        }
    }

    response += x;

    return response + divide(0, j, partial_sum[j], partial_sum) +
           divide(j + 1, end, partial_sum[end] - partial_sum[j], partial_sum);
}

int main() {
    int n, x;
    std::cin >> x >> n;
    std::vector<int> vc(n);
    std::vector<int> partial_sum(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> vc[i];
        partial_sum[i] = (i > 0 ? partial_sum[i - 1] : 0) + vc[i];
    }

    int response = divide(0, n - 1, x, partial_sum);

    std::cout << response << std::endl;
}