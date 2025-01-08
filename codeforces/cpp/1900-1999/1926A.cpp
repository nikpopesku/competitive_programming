#include <iostream>

int main() {
    int t;
    std::string s;
    unsigned int counter;
    std::cin >> t;

    for (auto i = 0; i < t; i++) {
        std::cin >> s;

        counter = 0;

        for (auto j = 0; j < s.size() and counter < 3; j++) {
            if (s[j] == 'A') counter++;
        }

        std::cout << (counter >= 3 ? 'A' : 'B') << std::endl;
    }
}
