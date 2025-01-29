#include <iostream>

int main() {
    int q, value, x, k;
    std::cin >> q;

    for (int i = 0; i < q; ++i) {
        std::cin >> value;
        if (value == 1) {
            std::cin >> x;
        } else {
            std::cin >> x >> k;
        }
    }
}