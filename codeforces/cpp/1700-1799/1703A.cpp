#include <iostream>

int main() {
    int t;
    std::string s;

    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::cin >> s;

        for (auto &c: s) {
            c = tolower(c);
        }

        std::cout << (s == "yes" ? "YES" : "NO") << std::endl;
    }
}