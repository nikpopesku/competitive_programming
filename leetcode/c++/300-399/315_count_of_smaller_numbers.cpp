#include <iostream>
#include <vector>

using namespace std;

class Bit {
public:
    Bit(int sz) : n(sz), tree(sz + 1) {
    }

    int query(int index) {
    }

    void update(int index, const int delta) {
        ++index;

        while (index <= n) {
            tree[index] += delta;
            index += index & -index;
        }
    }

private:
    int n;
    vector<int> tree;
};

class Solution {
public:
    vector<int> countSmaller(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        int maxval = nums[0];
        for (auto &e: nums) maxval = max(maxval, e);
        Bit bt(maxval);

        for (int i = maxval; i >= 0; --i) {
            const int val = bt.query(nums[i] - 1);
            bt.update(i, val + 1);
        }

        vector<int> response;

        for (int i = 0; i < n; ++i) {
            response.push_back(bt.query(i));
        }

        return response;
    }
};


int main() {
    vector nums = {5, 2, 6, 1};
    for (auto na = Solution(); auto &i: na.countSmaller(nums)) {
        cout << i << "\n";
    }
}
