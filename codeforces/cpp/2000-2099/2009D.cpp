#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::vector<std::tuple<int, int> > points{};
        for (auto j = 0; j < n; j++) {
            int x, y;
            std::cin >> x >> y;
            points.emplace_back(x, y);
        }

        long long counter = 0;
        for (auto k1 = 0; k1 < points.size() - 2; k1++) {
            for (auto k2 = k1 + 1; k2 < points.size() - 1; k2++) {
                for (auto k3 = k2 + 1; k3 < points.size(); k3++) {
                    double line1 = std::pow(std::get<0>(points[k1]) - std::get<0>(points[k2]), 2) + std::pow(
                                       std::get<1>(points[k1]) - std::get<1>(points[k2]), 2);
                    double line2 = std::pow(std::get<0>(points[k1]) - std::get<0>(points[k3]), 2) + std::pow(
                                       std::get<1>(points[k1]) - std::get<1>(points[k3]), 2);
                    double line3 = std::pow(std::get<0>(points[k2]) - std::get<0>(points[k3]), 2) + std::pow(
                                       std::get<1>(points[k2]) - std::get<1>(points[k3]), 2);
                    const double max_elem = std::max(std::max(line1, line2), line3);
                    const double min_elem = std::min(std::min(line1, line2), line3);
                    if (max_elem - min_elem == line1 or max_elem - min_elem == line2 or max_elem - min_elem == line3) {
                        counter += 1;
                    }
                }
            }
        }

        std::cout << counter << std::endl;
    }

    return 0;
}
