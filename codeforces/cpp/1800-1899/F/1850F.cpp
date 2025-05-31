#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    int n;


    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::cin >> n;

        int frog;
        std::vector frogs(n + 1, 0);

        for (int j = 0; j < n; j++) {
            std::cin >> frog;

            if (frog > n) {
                continue;
            }

            frogs[frog] += 1;
        }

        std::vector multipliers(n + 1, std::vector<int>{});

        for (int j = 1; j < n + 1; j++) {
            if (frogs[j] == 0) continue;

            int value = j;
            while (value <= n) {
                multipliers[j].push_back(value);
                value += j;
            }
        }

        std::vector leaps(n + 1, 0);

        for (int j = 1; j < n + 1; j++) {
            if (frogs[j] == 0) continue;

            for (auto &elem: multipliers[j]) {
                leaps[elem] += frogs[j];
            }
        }

        std::cout << *std::max_element(leaps.begin(), leaps.end()) << std::endl;
    }

    return 0;
}