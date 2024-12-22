#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int t;
    int n;
    int coordinate;
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
            value = same_x[x];
            response += value * (value - 1) - (value - 1) * (value - 2);


            same_y[y] += 1;
            value = same_y[y];
            response += value * (value - 1) - (value - 1) * (value - 2);


            coordinate = x - y;
            positive_45[coordinate] += 1;
            value = positive_45[coordinate];
            response += value * (value - 1) - (value - 1) * (value - 2);


            coordinate = x + y;
            negative_45[coordinate] += 1;
            value = negative_45[coordinate];
            response += value * (value - 1) - (value - 1) * (value - 2);
        }

        std::cout << response << std::endl;
    }

    return 0;
}