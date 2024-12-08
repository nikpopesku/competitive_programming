#include <iostream>

int main() {
    int t;
    int n;
    std::string ch;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        std::cin >> n;
        for (auto j = 0; j < n; j++) {
            std::cin >> ch;
            for (unsigned k = 0; k < 4; k++) {
                if (ch[k] == '#') {
                    std::cout <<  - k;
                    if (j == n - 1) {
                        std::cout << std::endl;
                    } else {
                        std::cout << ' ';
                    }
                    break;
                }
            }
        }
    }

    return 0;
}
