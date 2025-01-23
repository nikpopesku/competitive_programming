#include <iostream>


int main() {
    int n, q, type, cur_value, value = 0;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;

    for (auto i = 1; i <= q; i++) {
        std::cin >> type >> cur_value;

        if (type == 2) {
            if (value) {
                std::string sub = s.substr(n-value, value);
                s.insert(0, sub);
                s.resize(n);
            }

            std::cout << s[cur_value - 1] << std::endl;
        }

        if (type == 1) {
            value += cur_value;
            value %= n;
        }
    }
}