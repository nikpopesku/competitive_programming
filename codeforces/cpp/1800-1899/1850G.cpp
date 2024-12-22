#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int t;
    int n;

    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::cin >> n;

        std::vector points_x(n, 0);
        std::vector points_y(n, 0);
        std::unordered_map<int, int> x {};
        std::unordered_map<int, int> y {};


        int response = 0;

        for (int j = 0; j < n; j++) {
            std::cin >> points_x[j] >> points_y[j];

            if (auto value = x.find(points_x[j]); value != x.end()) {
                x[value->first] += 1;
            } else {
                x[points_x[j]] = 1;
            }

            if (auto value = x.find(points_y[j]); value != y.end()) {
                y[value->first] += 1;
            } else {
                y[points_y[j]] = 1;
            }
        }

        for (auto &elem: x) {
            if (elem.second > 1) {
                response += elem.second * (elem.second - 1);
            }
        }

        for (auto &elem: y) {
            if (elem.second > 1) {
                response += elem.second * (elem.second - 1);
            }
        }

        std::cout << response << std::endl;
    }

    return 0;
}