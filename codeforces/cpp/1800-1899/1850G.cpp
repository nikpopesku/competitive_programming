#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int t;
    int n;
    int x, y;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::cin >> n;

        std::unordered_map<int, int> same_x, same_y, positive_45, negative_45;
        int response = 0;

        for (int j = 0; j < n; j++) {
            std::cin >> x >> y;

            same_x[x] += 1;
            same_y[y] += 1;
            positive_45[x - y] += 1;
            negative_45[x + y] += 1;
        }

        for (auto &elem: same_x) response += elem.second * (elem.second - 1);
        for (auto &elem: same_y) response += elem.second * (elem.second - 1);
        for (auto &elem: positive_45) response += elem.second * (elem.second - 1);
        for (auto &elem: negative_45) response += elem.second * (elem.second - 1);

        std::cout << response << std::endl;
    }

    return 0;
}