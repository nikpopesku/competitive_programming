#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    int n;


    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::cin >> n;

        std::vector multipliers (n+1, std::vector<int> {});

        for (int j = 1; j < n; j++) {
            int value = j;
            while (value <= n) {
                multipliers[value].push_back(value);
                value += j;
            }
        }

        int leap;
        std::vector leaps (n+1, 0);

        for (int j = 0; j < n; j++) {
            std::cin >> leap;

            if (leap > n) {
                continue;
            }

            for (auto & elem: multipliers[leap]) {
                leaps[elem] += 1;
            }
        }

        std::cout << *std::max_element(leaps.begin(), leaps.end()) << std::endl;
    }

    return 0;
}