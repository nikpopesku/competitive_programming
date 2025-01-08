#include <iostream>

int main() {
    int t, n;
    int first_line = 0;
    int second_line = 0;
    std::string s;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        std::cin >> n;

        first_line = 0;
        second_line = 0;

        for (auto j = 0; j < n; j++) {
            std::cin >> s;

            if (not first_line or not second_line) {
                for (auto k = 0; k < n; k++) {
                    if (s[k] == '1') {
                        second_line++;
                    }
                }

                if (first_line and second_line) {
                    std::cout << (first_line == second_line ? "SQUARE" : "TRIANGLE") << std::endl;
                } else {
                    first_line = second_line;
                    second_line = 0;
                }
            }
        }
    }
}
