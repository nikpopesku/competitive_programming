#include <iostream>

int main() {
    int t;
    int l, r;
    std::cin >> t;


    for (int i = 0; i < t; i++) {
        int response = 0;
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

        int current = l;
        for (auto j = start; j <= end; j++) {
            response += (std::min(3 * j, r) - current) * j;
            current = 3 * j - 1;
        }

        response += start;

        std::cout << response << std::endl;
    }
}
