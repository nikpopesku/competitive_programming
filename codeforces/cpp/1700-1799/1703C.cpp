#include <iostream>
#include <vector>

int main() {
    int t, n;
    std::cin >> t;
    int moves;
    std::string seq;
    int counter_d = 0;

    for (int i = 0; i < t; i++) {
        std::cin >> n;

        std::vector<int> fin(n);
        for (int j = 0; j < n; j++) std::cin >> fin[j];

        for (int j = 0; j < n; j++) {
            std::cin >> moves >> seq;

            counter_d = 0;

            for (auto &mv: seq) {
                if (mv == 'D') counter_d++;
            }

            if (counter_d + counter_d >= moves) {
                fin[j] += counter_d + counter_d - moves;
            } else {
                fin[j] += 10 - moves + counter_d + counter_d;
            }
        }

        for (auto j = 0; j < n - 1; j++) {
            std::cout << fin[j] % 10 << ' ';
        }

        std::cout << fin[n - 1] % 10 << std::endl;
    }
}