#include <iostream>
#include <vector>
#include <queue>


int main() {
    int n, m, value, willing_pay;
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
        price[i] = -1 * value;
    }

    for (int i = 0; i < m; ++i) {
        std::cin >> willing_pay;

        if (price[0] > willing_pay) {
            std::cout << -1 << std::endl;
            continue;
        }

        int left = 0, right = price.size() - 1, mid;

        while (left <= right) {
            mid = left + (right - left) / 2;

            if (price[mid] <= willing_pay and (mid == price.size() - 1 or price[mid + 1] > willing_pay)) {
                std::cout << price[mid] << std::endl;
                price.erase(price.begin() + mid);
                break;
            } else if (price[mid] <= willing_pay) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

}