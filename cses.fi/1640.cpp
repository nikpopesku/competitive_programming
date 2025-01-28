#include <iostream>
#include <map>

int main() {
    int n, x, value;
    std::cin >> n >> x;
    std::map<int, int> mp;
    bool found = false;

    for (int i = 1; i <= n; ++i) {
        std::cin >> value;
        if (!found and mp[x - value] != 0) {
            std::cout << mp[x-value] << ' ' << i << std::endl;
            found = true;
        } else if(!found) {
            mp[value] = i;
        }
    }

    if (!found) {
        std::cout << "IMPOSSIBLE\n";
    }
}