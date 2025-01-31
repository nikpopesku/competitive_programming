#include <iostream>
#include <queue>

using ll = long long;

int main() {
    ll n, value, x, response;
    std::cin >> x >> n;
    std::priority_queue<int> pq;

    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        pq.push(-1 * value);
    }

    while (pq.size() >= 2) {
        ll left = -1 * pq.top();
        pq.pop();
        ll right = -1 * pq.top();
        pq.pop();
        value = left + right
        response += value;
        pq.push(-1 * value);
    }

    std::cout << response << std::endl;
}