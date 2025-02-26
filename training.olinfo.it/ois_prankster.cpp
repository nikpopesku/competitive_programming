#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
    }
    if (n <= 1) {
        std::cout << 0 << std::endl;
        return 0;
    }
    std::vector<int> d(n);
    d[0] = s[0];
    for (int i = 1; i < n; ++i) {
        d[i] = s[i] - s[i - 1];
    }
    int operations_count = 0;
    for (int i = 1; i < n; ++i) {
        if (d[i] != 0) {
            operations_count++;
        }
    }
    std::cout << operations_count << std::endl;
    return 0;
}