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

                response += same_x[value->first] * (same_x[value->first] - 1);
                if (same_x[value->first] > 2) {
                    response -= (same_x[value->first] - 1) * (same_x[value->first] - 2);
                }
            } else {
                same_x[x] = 1;
            }

            if (auto value = same_y.find(y); value != same_y.end()) {
                same_y[value->first] += 1;

                response += same_y[value->first] * (same_y[value->first] - 1);
                if (same_y[value->first] > 2) {
                    response -= (same_y[value->first] - 1) * (same_y[value->first] - 2);
                }
            } else {
                same_y[y] = 1;
            }

            if (auto value = positive_45.find(x - y); value != positive_45.end()) {
                positive_45[value->first] += 1;


                response += positive_45[value->first] * (positive_45[value->first] - 1);
                if (positive_45[value->first] > 2) {
                    response -= (positive_45[value->first] - 1) * (positive_45[value->first] - 2);
                }
            } else {
                positive_45[x - y] = 1;
            }

            if (auto value = negative_45.find(x + y); value != negative_45.end()) {
                negative_45[value->first] += 1;

                response += negative_45[value->first] * (negative_45[value->first] - 1);
                if (negative_45[value->first] > 2) {
                    response -= (negative_45[value->first] - 1) * (negative_45[value->first] - 2);
                }
            } else {
                negative_45[x + y] = 1;
            }
        }

        std::cout << response << std::endl;
    }

    return 0;
}