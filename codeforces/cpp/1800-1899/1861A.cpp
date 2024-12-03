#include <array>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        std::string number;
        std::cin >> number;
        std::vector<int> numbers {};

        for (char j : number) {
            if (j == '1') {
                puts("13");
            } else {
                puts("31");
            }
        }
    }

    return 0;
}
