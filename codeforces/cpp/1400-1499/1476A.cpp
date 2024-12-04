#include <iostream>

int main() {
    int t;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        int n, k;
        std::cin >> n >> k;

        const int initial_k = k;
        while (k < n) {
            k += initial_k;
        }

        int start = 1;
        while (start <= k) {
            if (n * start >= k) {
                std::cout << start << std::endl;
                break;
            }
            start++;
        }
    }

    return 0;
}
