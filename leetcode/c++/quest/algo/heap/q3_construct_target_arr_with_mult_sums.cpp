#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPossible(const vector<int> &target) {
        priority_queue<long long> pq;
        long long total = 0;

        for (int x : target) {
            pq.push(x);
            total += x;
        }

        // Undo operations: the max element was the last one replaced with the sum.
        // Before that op: old_val = max - rest = max % rest (skip multiple steps).
        while (pq.top() > 1) {
            const long long a = pq.top();
            pq.pop();

            const long long rest = total - a;

            if (rest == 0 || a <= rest) return false;

            long long prev = a % rest;
            if (prev == 0) prev = rest;

            total = rest + prev;
            pq.push(prev);
        }

        return true;
    }
};


int main() {
    auto s = Solution();
    cout << boolalpha;
    cout << s.isPossible({9, 3, 5})       << '\n'; // true
    cout << s.isPossible({1, 1, 1, 2})    << '\n'; // false
    cout << s.isPossible({8, 5})          << '\n'; // true
    cout << s.isPossible({1, 1000000000}) << '\n'; // true
    cout << s.isPossible({1})             << '\n'; // true
    cout << s.isPossible({2})             << '\n'; // false
    cout << s.isPossible({2, 7})          << '\n'; // true
    cout << s.isPossible({4, 10})         << '\n'; // false
    cout << s.isPossible({1, 1, 61, 9, 17}) << '\n'; // true
}
