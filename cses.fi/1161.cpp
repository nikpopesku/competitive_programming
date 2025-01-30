#include <iostream>
#include <vector>

int main() {
    int n, x;
    std::cin >> x >> n;
    std::vector<int> vc(n);
    std::vector<int> partial_sum(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> vc[i];
        partial_sum[i] = (i >= 1 ? partial_sum[i-1] : 0) + vc[i];
    }
}