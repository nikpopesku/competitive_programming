#include <iostream>
#include <vector>

using namespace std;

class Bit {
public:
    explicit Bit(const int sz) : n(sz), tree(sz + 1) {
    }

    int query(int index) const {
        int response = 0;

        while (index > 0) {
            response += tree[index];
            index -= index & -index;
        }

        return response;
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
    vector<int> countSmaller(const vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        int maxval = nums[0];
        for (auto &e: nums) maxval = max(maxval, e);
        Bit bt(maxval);

        for (int i = n - 1; i >= 0; --i) {
            const int val = bt.query(nums[i] - 1);
            bt.update(nums[i], val + 1);
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
    for (auto na = Solution(); const auto &i: na.countSmaller(nums)) {
        cout << i << "\n";
    }
}
