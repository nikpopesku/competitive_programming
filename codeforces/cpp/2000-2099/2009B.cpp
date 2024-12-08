#include <iostream>
#include <vector>

int main() {
    int t;
    int n;
    std::string ch;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        std::cin >> n;
        std::vector<unsigned int> response(n, 0);
        for (auto j = 0; j < n; j++) {
            std::cin >> ch;
            for (unsigned int k = 0; k < 4; k++) {
                if (ch[k] == '#') {
                    response[n - j - 1] = k + 1;
                    break;
                }
            }
        }
        for (size_t j = 0; j < n; j++) {
            std::cout << response[j];
            if (j == n - 1) {
                std::cout << std::endl;
            } else {
                std::cout << ' ';
            }
        }
    }

    return 0;
}
