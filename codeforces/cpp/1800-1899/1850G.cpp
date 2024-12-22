#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int t;
    int n;
    int coord;
    long long value;

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

            same_x[x] += 1;
            response += same_x[x] * (same_x[x] - 1) - (same_x[x] - 1) * (same_x[x] - 2);


            same_y[y] += 1;
            response += same_y[y] * (same_y[y] - 1) - (same_y[y] - 1) * (same_y[y] - 2);


            coord = x - y;
            positive_45[coord] += 1;
            response += positive_45[coord] * (positive_45[coord] - 1) - (positive_45[coord] - 1) * (positive_45[coord] - 2);


            coord = x + y;
            negative_45[coord] += 1;
            response += negative_45[coord] * (negative_45[coord] - 1) - (negative_45[coord] - 1) * (negative_45[coord] - 2);
        }

        std::cout << response << std::endl;
    }

    return 0;
}