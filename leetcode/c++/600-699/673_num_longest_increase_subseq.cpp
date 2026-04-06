#include <iostream>
#include <vector>

using namespace std;

class Bit {
public:
    explicit Bit(const int sz) : n(sz), tree(sz + 1, 0) {
    }

private:
    int n;
    vector<int> tree;
};

class Solution {
public:
    int findNumberOfLIS(const vector<int> &nums) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        int n = static_cast<int>(nums.size());
        int m = static_cast<int>(v.size());

        for (int i = 0; i < n; ++i) {
        }
    }
};

int main() {
    Solution s;

    vector<int> nums = {1, 3, 5, 4, 7};
    cout << s.findNumberOfLIS(nums) << endl;

    vector<int> nums2 = {2, 2, 2, 2, 2};
    cout << s.findNumberOfLIS(nums2) << endl;

    return 0;
}
