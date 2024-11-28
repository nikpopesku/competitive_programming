#include <iostream>
#include <vector>

int main() {
    int t, n, k;


    std::cin >> t;
    std::vector response(t, 0);

    for (int i = 0; i < t; i++) {
        std::cin >> n >> k;

        std::vector numbers(n, 0);
        unsigned long long product = 1;

        for (int j = 0; j < n; j++) {
            std::cin >> numbers[j];
            product = product * numbers[j];
        }

        if (product % k == 0) {
          continue;
        }


    }

    for (auto &elem: response) {
        std::cout << elem;
    }

    return 0;
}
