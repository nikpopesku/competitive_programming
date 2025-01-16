#include <iostream>
#include <map>

int main() {
    int n, value;
    std::cin >> n;

    std::map<int, int> mp;

    for (auto i = 1; i <= n; i++) {
        std::cin >> value;

        if (mp.find(value) != mp.end()) {
            mp[value] += 1;

            continue;
        }

        mp[value] = 1;
    }

    long long response = n * (n - 1) / 2;
    for (auto &elem: mp) response -= elem.second * (elem.second - 1) / 2;

    std::cout << response << std::endl;
}