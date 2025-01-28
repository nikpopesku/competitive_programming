#include <iostream>
#include <set>


int main() {
    int n, m, value, willing_pay;
    std::cin >> n >> m;
    std::set<int> price;

    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        price.insert(value);
    }

    for (int i = 0; i < m; ++i) {
        std::cin >> willing_pay;

        if (price.empty()) {
            std::cout << -1 << std::endl;
            continue;
        }

        auto it = price.lower_bound(willing_pay);
        std::cout << *it << std::endl;
        price.erase(*it);
    }

}