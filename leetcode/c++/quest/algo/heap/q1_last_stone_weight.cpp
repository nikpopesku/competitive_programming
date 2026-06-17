#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int lastStoneWeight(const vector<int> &stones) {
        priority_queue<int> pq;

        for (int i = 0; i < static_cast<int>(stones.size()); ++i) {
            pq.push(stones[i]);
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
