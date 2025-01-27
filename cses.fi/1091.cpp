#include <iostream>
#include <vector>
#include <queue>


int main() {
    int n, m, value;
    std::cin >> n >> m;
    std::vector<int> price(n);
    std::priority_queue<int> pq;

    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        pq.push(-1 * value);
    }

    for (int i = 0; i < n; ++i) {
        value = pq.top();
        pq.pop();
        price.push_back(-1 * value);
    }

    for (int i = 0; i < m; ++i) {
        std::cin >> value;
        int left = 0, right = price.size() - 1;

        while (left < right) {
            m = left + (right - left) / 2;

            if (m == 0 and price[m] > value) {
                std::cout << -1 << std::endl;
                break;
            } else if (price[m] <= value and (m == price.size() - 1 or price[m + 1] < value)) {
                std::cout << price[m] << std::endl;
                price.erase(price.begin() + m);
                break;
            } else if (value >= price[m]) {
                left = m + 1;
            } else {
                right = m;
            }
        }
    }

}