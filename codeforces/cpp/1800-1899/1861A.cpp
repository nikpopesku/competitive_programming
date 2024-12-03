#include <array>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        std::string number;
        std::cin >> number;
        std::vector<int> numbers{};

        for (const char digit: number) {
            if (digit == '1') {
                puts("13");
                break;
            }
            if (digit == '3') {
                puts("31");
                break;
            }
        }
    }

    return 0;
}
