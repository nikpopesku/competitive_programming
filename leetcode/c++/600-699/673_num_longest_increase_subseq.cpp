#include <iostream>
#include <vector>

using namespace std;

struct Lis {
    int max_length;
    int count;
};

class Bit {
public:
    explicit Bit(const int sz) : n(sz), tree(sz + 1, 0) {
    }

    void update(int index) {

    }

    int query(int index) const {
        Lis response = {};
        while (index > 0) {
            if (tree[index].max_length > response.max_length) {
                response = tree[index];
            }

            if (tree[index].max_length == response.max_length) {
                response.count += tree[index].count;
            }

            index -= index & -index;
        }

        return response.max_length;
    }
private:
    int n;
    vector<Lis> tree;
};

class Solution {
public:
    int findNumberOfLIS(const vector<int> &nums) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        const int n = static_cast<int>(nums.size());
        const int m = static_cast<int>(v.size());
        Bit bt(m);

        for (int i = 0; i < n; ++i) {
            int rank = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
            bt.query(rank - 1);
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
