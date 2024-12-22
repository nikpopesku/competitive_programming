#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int t;
    int n;

    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::cin >> n;

        int x, y;
        std::unordered_map<int, long long> same_x{};
        std::unordered_map<int, long long> same_y{};
        std::unordered_map<int, long long> positive_45{};
        std::unordered_map<int, long long> negative_45{};


        long long response = 0;

        for (int j = 0; j < n; j++) {
            std::cin >> x >> y;

            if (auto value = same_x.find(x); value != same_x.end()) {
                same_x[value->first] += 1;
            } else {
                same_x[x] = 1;
            }

            if (auto value = same_y.find(y); value != same_y.end()) {
                same_y[value->first] += 1;
            } else {
                same_y[y] = 1;
            }

            if (auto value = positive_45.find(x - y); value != positive_45.end()) {
                positive_45[value->first] += 1;
            } else {
                positive_45[x - y] = 1;
            }

            if (auto value = negative_45.find(x + y); value != negative_45.end()) {
                negative_45[value->first] += 1;
            } else {
                negative_45[x + y] = 1;
            }
        }

        for (auto &elem: same_x) {
            if (elem.second > 1) {
                response += elem.second * (elem.second - 1);
            }
        }

        for (auto &elem: same_y) {
            if (elem.second > 1) {
                response += elem.second * (elem.second - 1);
            }
        }

        for (auto &elem: positive_45) {
            if (elem.second > 1) {
                response += elem.second * (elem.second - 1);
            }
        }

        for (auto &elem: negative_45) {
            if (elem.second > 1) {
                response += elem.second * (elem.second - 1);
            }
        }

        std::cout << response << std::endl;
    }

    return 0;
}