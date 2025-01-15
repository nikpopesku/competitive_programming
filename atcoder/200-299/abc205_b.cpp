#include <iostream>
#include <map>

int main() {
    unsigned int n, value;
    std::cin >> n;

    std::map<unsigned int, unsigned int> mp;

    for (auto i = 1; i <= n; i++) {
        std::cin >> value;

        if (value < 1 or value > n) {
            std::cout << "No" << std::endl;
            return 0;
        }

        if (mp.find(value) != mp.end()) {
            std::cout << "No" << std::endl;
            return 0;
        }

        mp[value] = value;
    }

    std::cout << "Yes\n";
}