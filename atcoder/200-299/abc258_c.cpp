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
            std::string sub = s.substr(n-value-1, value);
            s.insert(0, sub);
            s.resize(n);
        }
    }
}