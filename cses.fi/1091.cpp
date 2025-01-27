#include <iostream>
#include <vector>


int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<int> price(n);
    std::vector<int> mx(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> price[i];
    }

    for (int i = 0; i < m; ++i) {
        std::cin >> mx[i];
    }
}