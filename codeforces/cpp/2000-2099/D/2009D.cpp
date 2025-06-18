#include <iostream>
#include <vector>
#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;

    struct hashFunction {
        size_t operator()(const std::tuple<int, int> &x) const {
            return get<0>(x) ^ get<1>(x);
        }
    };

    for (auto i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::unordered_set<std::tuple<int, int>, hashFunction> points;

        for (auto j = 0; j < n; j++) {
            int x, y;
            std::cin >> x >> y;
            points.insert(std::make_tuple(x, y));
        }

        unsigned long long counter = 0;
        for (const auto &point: points) {
            auto x = get<0>(point);
            auto y = get<1>(point);
            if (auto got1 = points.find(std::make_tuple(x+2, y)); got1 != points.end()) {
                if (auto got2 = points.find(std::make_tuple(x+1, y ^ 1)); got2 != points.end()) {
                    counter += 1;
                }
            }
            if (auto got1 = points.find(std::make_tuple(x, 1)); got1 != points.end() and y == 0) {
                counter += points.size() - 2;
            }
        }

        std::cout << counter << std::endl;
    }

    return 0;
}
