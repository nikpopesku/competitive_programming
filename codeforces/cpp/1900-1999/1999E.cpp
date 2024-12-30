#include <iostream>
#include <cmath>

int main() {
    int t;
    long long l, r;
    std::cin >> t;


    for (int i = 0; i < t; i++) {
        long long response = 0;
        std::cin >> l >> r;

        int start = 0;
        int end = 0;

        int val = l;
        while (val > 0) {
            start += 1;
            val /= 3;
        }

        val = r;
        while (val > 0) {
            end += 1;
            val /= 3;
        }

        long long current = l - 1;
        for (auto j = start; j <= end; j++) {
            long long xxx = pow(3, j);
            response += (std::min(xxx, r) - current) * j;
            current = xxx;
        }

        response += start;

        std::cout << response << std::endl;
    }
}
