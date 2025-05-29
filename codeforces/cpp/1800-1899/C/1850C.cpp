#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        std::string word{};
        std::string response{};
        for (auto j = 0; j < 8; j++) {
            std::string s;
            std::cin >> s;

            for (auto &ch: s) {
                if (ch != '.') {
                    response += ch;
                }
            }
        }

        std::cout << response << std::endl;
    }

    return 0;
}
