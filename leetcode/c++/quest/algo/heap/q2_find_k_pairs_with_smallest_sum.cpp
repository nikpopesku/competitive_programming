#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
    }
};

int main() {
    auto s = Solution();
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    for (auto &x: s.kSmallestPairs(nums1, nums2, 3)) {
        for (auto &y: x) cout << y << ' ';
    }
    cout << '\n';

    vector<int> nums12 = {1, 1, 2};
    vector<int> nums22 = {1, 2, 3};
    for (auto &x: s.kSmallestPairs(nums12, nums22, 2)) {
        for (auto &y: x) cout << y << ' ';
    }
    cout << '\n';
}
