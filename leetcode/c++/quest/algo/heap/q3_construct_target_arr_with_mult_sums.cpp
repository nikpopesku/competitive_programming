#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPossible(const vector<int>& target) {
        long long total = 0;
        priority_queue<long long> pq;

        for (auto &t: target) {
            total += t;
            pq.push(t);
        }

        while (pq.top() > 1) {
            const long long elem = pq.top();
            pq.pop();

            const long long rest = total - elem;
            if (rest == 0 || elem <= rest) return false;

            long long prev = elem % rest;

            if (elem % rest == 0) {
                prev = rest;
            }

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
