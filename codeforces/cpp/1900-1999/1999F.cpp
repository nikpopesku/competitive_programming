#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    int n, k, value;

    for (int i = 0; i < t; i++) {
        std::cin >> n >> k;

        int count_zero = 0;
        std::vector<int> vec (n, 1);

        for (int j = 0; j < n; j++) {
            std::cin >> value;
            if (value == 0) count_zero++;
        }

        for (int j = 0; j < count_zero; j++) vec[j] = 0;
    }
}
