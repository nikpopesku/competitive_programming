#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<bool> present(n + 2, false);
    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        if (a >= 1 && a <= n + 1) {
            present[a] = true;
        }
    }
    for (int i = 1; i <= n + 1; ++i) {
        if (!present[i]) {
            std::cout << i << std::endl;
            break;
        }
    }
    return 0;
}