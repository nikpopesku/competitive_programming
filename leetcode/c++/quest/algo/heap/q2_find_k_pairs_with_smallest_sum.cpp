#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

    }
};

int main() {
    auto s = Solution();
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << s.lastStoneWeight(stones) << '\n';

    vector<int> stones2 = {1};
    cout << s.lastStoneWeight(stones2) << '\n';
}
