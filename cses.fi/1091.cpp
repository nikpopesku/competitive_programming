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
        price[i] = -1 * value;
    }

    for (int i = 0; i < m; ++i) {
        std::cin >> value;
        int left = 0, right = price.size() - 1, mid;

        while (left < right) {
            mid = left + (right - left) / 2;

            if (mid == 0 and price[mid] > value) {
                std::cout << -1 << std::endl;
                break;
            } else if (price[mid] <= value and (mid == price.size() - 1 or price[mid + 1] < value)) {
                std::cout << price[mid] << std::endl;
                price.erase(price.begin() + mid);
                break;
            } else if (price[mid] <= value and left != mid) {
                left = mid;
            } else if (price[mid] <= value and left == mid) {
                right = mid;
            } else {
                right = mid - 1;
            }
        }

        if (left == right) {
            if (price[left] <= value) std::cout << price[left] << std::endl;
            if (price[left] > value) std::cout << -1 << std::endl;
        }
    }

}