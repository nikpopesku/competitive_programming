#include <iostream>
#include <cmath>

int main() {
    int t;
    long long n;
    long long c, side;

    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::cin >> n >> c;

        long long sum = 0;
        long long double_sum = 0;

        for (int j = 0; j < n; j++) {
            std::cin >> side;

            sum += side;
            double_sum += side * side;
        }

        long long response = (-sum + sqrt(sum * sum + n * (c - double_sum))) / (2 * n);

        std::cout << response << std::endl;
    }

    return 0;
}