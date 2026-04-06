#include <iostream>
#include <vector>

using namespace std;

struct Lis {
    int max_length = 0;
    int count = 0;
};

class Bit {
public:
    explicit Bit(const int sz) : n(sz), tree(sz + 1, 0) {
    }

    void update(int index, const int length, const int count) {
        ++index;

        while (index <= n ) {
            if (length > tree[index].max_length) {
                tree[index] = Lis{length, count};
            } else if (length == tree[index].max_length) {
                ++tree[index].count;
            }

        }
    }

    Lis query(int index) const {
        ++index;
        Lis response = {};

        while (index > 0) {
            if (tree[index].max_length > response.max_length) {
                response = tree[index];
            } else if (tree[index].max_length == response.max_length) {
                response.count += tree[index].count;
            }

            index -= index & -index;
        }

        return response;
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
            const int rank = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
            Lis val = bt.query(rank - 1);

            bt.update(rank, val.max_length, val.count);
        }

        // return bt.query()
    }
};

int main() {
    Solution s;

    const vector<int> nums = {1, 3, 5, 4, 7};
    cout << s.findNumberOfLIS(nums) << endl;

    const vector<int> nums2 = {2, 2, 2, 2, 2};
    cout << s.findNumberOfLIS(nums2) << endl;

    return 0;
}
