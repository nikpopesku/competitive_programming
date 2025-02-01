#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    int max_value = 0;


    for (auto i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::vector<int> vc(2 * n);

        for (int j = 0; j < 2 * n; ++j) {
            std::cin >> vc[j];
            if (vc[j] > max_value) max_value = vc[j];
        }
    }
}
