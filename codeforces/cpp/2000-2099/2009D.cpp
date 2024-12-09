#include <iostream>
#include <vector>
#include <bits/stdc++.h>

bool comp(const std::tuple<int, int> &a, const std::tuple<int, int> &b) {
    return std::get<0>(a) <= std::get<0>(b);
}

int main() {
    int t;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::vector<std::tuple<int, int>> points0{};
        std::vector<std::tuple<int, int>> points1{};

        std::unordered_set<std::string> points;
        for (auto j = 0; j < n; j++) {
            int x, y;
            std::cin >> x >> y;
            if (y == 1) {
                points1.emplace_back(x, y);
            } else {
                points0.emplace_back(x, y);
            }
            points.insert(std::to_string(x) + "_" + std::to_string(y));
        }

        std::ranges::sort(points1, comp);
        std::ranges::sort(points0, comp);

        long long counter = 0;
        for (auto k1 = 0; k1 < points0.size() - 1; k1++) {
            for (auto k2 = k1 + 1; k2 < points0.size(); k2++) {
                const int x1 = std::get<0>(points0[k1]);
                const int x2 = std::get<0>(points0[k2]);
                if (auto got = points.find(std::to_string(x1) + "_1"); got != points.end()) {
                    counter += 1;
                }
                if (auto got = points.find(std::to_string(x2) + "_1"); got != points.end()) {
                    counter += 1;
                }
                if (x2 == x1 + 4) {
                    if (auto got = points.find(std::to_string(x1 + 2) + "_1"); got != points.end()) {
                        counter += 1;
                    }
                }
            }
        }

        for (auto k1 = 0; k1 < points1.size() - 1; k1++) {
            for (auto k2 = k1 + 1; k2 < points1.size(); k2++) {
                const int x1 = std::get<0>(points0[k1]);
                const int x2 = std::get<0>(points0[k2]);
                if (auto got = points.find(std::to_string(x1) + "_1"); got != points.end()) {
                    counter += 1;
                }
                if (auto got = points.find(std::to_string(x2) + "_1"); got != points.end()) {
                    counter += 1;
                }
                if (x2 == x1 + 4) {
                    if (auto got = points.find(std::to_string(x1 + 2) + "_1"); got != points.end()) {
                        counter += 1;
                    }
                }
            }
        }

        std::cout << counter << std::endl;
    }

    return 0;
}
