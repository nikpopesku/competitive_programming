#include <iostream>
#include <map>

int main() {
    int n, value;
    std::cin >> n;

    std::map<int, int> mp;
    int unique = 0;

    for (auto i = 1; i <= n; i++) {
        std::cin >> value;

        if (mp.find(value) != mp.end()) {
            mp[value] += 1;

            continue;
        }

        mp[value] = 1;
    }

    if (mp.size() <= 1) {
        std::cout << "0\n";
    }

    long long response;


    for (auto& elem: mp) {
        if (elem.second == 1) {
            unique++;
        }
    }

    if (unique > 1) {
        response = 0;
    } else {
        response = 1;
    }

    for (auto i = 1; i < unique; i++) {
        response += i;
    }


    for (auto& elem: mp) {
        if (elem.second > 1) {
            response *= elem.second;
        }
    }


    std::cout << response << std::endl;
}