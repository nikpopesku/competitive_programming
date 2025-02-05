#include <iostream>


int main() {
    int n, q, type, x;
    std::string s;
    std::cin >> n >> q >> s;
    int beg = 0;

    for (auto i = 1; i <= q; i++) {
        std::cin >> type >> x;

        if (type == 2) {
            x--;
            std::cout << s[(beg + x) % n] << '\n';
        }

        if (type == 1) {
            beg = (beg + n - x) % n;
        }
    }
}