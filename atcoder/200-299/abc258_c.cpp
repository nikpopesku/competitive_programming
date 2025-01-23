#include <iostream>


int main() {
    int n, q, type, value;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;

    for (auto i = 1; i <= q; i++) {
        std::cin >> type >> value;

        if (type == 2) {
            std::cout << s[value - 1] << std::endl;
        }

        if (type == 1) {
            value = value % n;

            while (value > 0) {
                s.insert(0, 1, s.back());
                s.resize(n);
                value--;
            }
        }
    }
}