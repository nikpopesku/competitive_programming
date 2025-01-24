#include <iostream>
#include <queue>


int main() {
    long long n, w, a, b;
    std::cin >> n >> w;
    std::priority_queue<std::pair<long long, long long>> pq;

    for (long long i = 0; i < n; i++) {
        std::cin >> a >> b;
        pq.emplace(a, b);
    }

    long long response = 0;
    long long count = 0;

    while (count < w and !pq.empty()) {
        auto tp = pq.top();
        response += tp.first * std::min(tp.second, w - count);
        if (tp.second <= w - count) pq.pop();
        count += std::min(tp.second, w - count);
    }

    std::cout << response << std::endl;
}