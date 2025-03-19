#include <iostream>
#include <vector>

int main() {
    int t, n;
    std::string s;

    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::cin >> n;
        std::cin >> s;

        std::vector<int> alphabet(26, 0);
        int sum = 0;

        for (auto &ch: s) {
            int index = int(ch) - int('A');
            int increase = alphabet[index] == 0 ? 2 : 1;
            alphabet[index] += increase;
            sum += increase;
        }

        std::cout << sum << std::endl;
    }
}