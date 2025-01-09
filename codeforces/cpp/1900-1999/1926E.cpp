#include <iostream>
#include <vector>
#include <map>

int main() {
    int t, k, n;
    std::cin >> t;


    for (auto i = 0; i < t; i++) {
        std::cin >> n >> k;

        std::vector<int> data;

        while (n) {
            data.push_back((n + 1) / 2);
            n /= 2;
        }

        int total = 0;
        int pow2 = 1;
        for (auto &elem: data) {
            if (total < k and total + elem >= k) {
                std::cout << pow2 * (2 * (k - total) - 1) << std::endl;
                break;
            }

            total += elem;
            pow2 *= 2;
        }
    }
}
