#include <iostream>

int main() {
    int t;
    int l, r;
    std::cin >> t;
    int response;

    for (int i = 0; i < t; i++) {
        std::cin >> l >> r;

        int val = l;
        response = 0;

        while (val > 0) {
            response += 2;
            val /= 3;
        }

        for (int j = l + 1; j <= r; j++) {
            val = j;
            while (val > 0) {
                response += 1;
                val /= 3;
            }
        }

        std::cout << response << std::endl;
    }
}
