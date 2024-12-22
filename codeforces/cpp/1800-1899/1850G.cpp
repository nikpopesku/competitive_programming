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

            if (same_x.find(x) == same_x.end()) {
                same_x[x] = 0;
            }
            same_x[x] += 1;
            value = same_x[x];
            response += value * (value - 1) - (value - 1) * (value - 2);


            if (same_y.find(y) == same_y.end()) {
                same_y[y] = 0;
            }
            same_y[y] += 1;
            value = same_y[y];
            response += value * (value - 1) - (value - 1) * (value - 2);


            coordinate = x - y;
            if (positive_45.find(coordinate) == positive_45.end()) {
                positive_45[coordinate] = 0;
            }
            positive_45[coordinate] += 1;
            value = positive_45[coordinate];
            response += value * (value - 1) - (value - 1) * (value - 2);


            coordinate = x + y;
            if (negative_45.find(coordinate) == negative_45.end()) {
                negative_45[coordinate] = 0;
            }
            negative_45[coordinate] += 1;
            value = negative_45[coordinate];
            response += value * (value - 1) - (value - 1) * (value - 2);
        }

        std::cout << response << std::endl;
    }

    return 0;
}