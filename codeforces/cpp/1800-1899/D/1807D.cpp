#include <iostream>
#include <queue>

int main() {
    int t, n, k;

    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::cin >> n >> k;

        int problem;
        std::priority_queue<int> pq;

        for (int j = 0; j < n; j++) {
            std::cin >> problem;
            pq.push(problem);
        }

        int largest_group = 1;
        int current_group = 1;
        int previous_number = pq.top();
        pq.pop();
        while (!pq.empty()) {
            if (previous_number - pq.top() <= k) {
                current_group += 1;
            } else {
                largest_group = std::max(largest_group, current_group);
                current_group = 1;
            }
            previous_number = pq.top();
            pq.pop();
        }

        largest_group = std::max(largest_group, current_group);
        std::cout << n - largest_group << std::endl;
    }

    return 0;
}