#include <iostream>
#include <map>
#include <vector>


int main() {
    int n, q, value, x, k;
    std::map<int, std::vector<int>> mp;
    std::cin >> n >> q;

    for (int i = 1; i < n; ++i) {
        std::cin >> value;
        mp[value].push_back(i);
    }

    for (int i = 0; i < q; ++i) {
        std::cin >> x >> k;

        if (mp[x].size() < k) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << mp[x][k-1] << std::endl;
        }
    }
}