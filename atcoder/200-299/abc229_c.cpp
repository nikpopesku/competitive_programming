#include <iostream>
#include <queue>


int main() {
    int n, w, a, b;
    std::cin >> n >> w;
    std::priority_queue<std::pair<int, int>> pq;

    for (int i = 0; i < n; i++) {
        std::cin >> a >> b;
        pq.push(std::make_pair(a, b));
    }

    int response = 0;
    int count = 0;

    while (count < w) {
        auto tp = pq.top();
        response += tp.first * std::min(tp.second, w - count);
        count += std::min(tp.second, w - count);

        if (tp.second <= w - count) pq.pop();
    }

    std::cout << response << std::endl;
}