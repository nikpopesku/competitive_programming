#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int> &stones) {
    }
};

int main() {
    auto s = Solution();
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << s.lastStoneWeight(stones) << '\n';

    vector<int> stones2 = {1};
    cout << s.lastStoneWeight(stones2) << '\n';
}
