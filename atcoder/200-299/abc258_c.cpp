#include <iostream>


int main() {
    int n, q, type, cur_value, value = 0;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;

    for (auto i = 1; i <= q; i++) {
        std::cin >> type >> cur_value;

        if (type == 2) {
            int zz = cur_value - 1 - value % n;
            if (zz < 0 ) zz += n;
            std::cout << s[zz] << std::endl;
        }

        if (type == 1) {
            value += cur_value;
        }
    }
}