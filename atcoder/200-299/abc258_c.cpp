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
    }
}