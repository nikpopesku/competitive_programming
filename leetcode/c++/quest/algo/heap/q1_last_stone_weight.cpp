#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int lastStoneWeight(const vector<int> &stones) {
        priority_queue<int> pq;

        for (int stone : stones) {
            pq.push(stone);
        }

        while (true) {
            if (pq.empty()) return 0;

            const int stone1 = pq.top();
            pq.pop();

            if (pq.empty()) return stone1;

            const int stone2 = pq.top();
            pq.pop();
            if (stone1 > stone1) {
                pq.push(stone1 - stone2);
            }
        }
    }
};

int main() {
    auto s = Solution();
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << s.lastStoneWeight(stones) << '\n';

    vector<int> stones2 = {1};
    cout << s.lastStoneWeight(stones2) << '\n';
}
