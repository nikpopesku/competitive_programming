#include <iostream>
#include <vector>
#include <map>

int main() {
    long long t;
    long long n;
    long long x, y;
    std::cin >> t;

    for (long long i = 0; i < t; i++) {
        std::cin >> n;

        std::map<long long, long long> same_x, same_y, positive_45, negative_45;
        long long response = 0;

        for (long long j = 0; j < n; j++) {
            std::cin >> x >> y;

            same_x[x]++;
            same_y[y]++;
            positive_45[x - y]++;
            negative_45[x + y]++;
        }

        for (auto &elem: same_x) response += elem.second * (elem.second - 1);
        for (auto &elem: same_y) response += elem.second * (elem.second - 1);
        for (auto &elem: positive_45) response += elem.second * (elem.second - 1);
        for (auto &elem: negative_45) response += elem.second * (elem.second - 1);

        std::cout << response << std::endl;
    }

    return 0;
}