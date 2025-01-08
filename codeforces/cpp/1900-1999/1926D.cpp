#include <iostream>
#include <unordered_map>

int main() {
    int t, n;
    int number;
    int groups = 0;
    int reverse;
    std::cin >> t;



    for (auto i = 0; i < t; i++) {
        std::cin >> n;

        std::unordered_map<int, int> mp{};
        groups = 0;

        for (auto j = 0; j < n; j++) {
            std::cin >> number;

            if (mp.find(number) != mp.end()) {
                mp[number]--;
                groups++;

                if (mp[number] == 0) {
                    mp.erase(number);
                }
            } else {
                reverse = ~number;

                if (mp.find(reverse) != mp.end()) {
                    mp[reverse]++;
                } else {
                    mp[reverse] = 1;
                }
            }
        }

        for (auto &elem: mp) {
            groups += elem.second;
        }

        std::cout << groups << std::endl;

    }
}
