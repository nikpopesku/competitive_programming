#include <iostream>
#include <vector>

using namespace std;

class Bit {
public:
    explicit Bit(const int sz) : n(sz), tree(sz + 1, 0) {
    }

    void update(int index) {
    }

    int query(int index) const {
        int response = 0;

        while (index > 0) {
            response += tree[index];
            index -= index & -index;
        }

        return response;
    }

private:
    int n;
    vector<int> tree;
};

class Solution {
public:
    int reversePairs(const vector<int> &nums) {
        const int n = static_cast<int>(nums.size());
        Bit bt(n);
        int response = 0;

        for (int i = n - 1; i >= 0; --i) {
            response += bt.query(nums[i]);
            bt.update(nums[i]);
        }

        return response;
    }
};


int main() {
    vector nums = {1, 3, 2, 3, 1};
    auto na = Solution();
    cout << na.reversePairs(nums) << "\n";
}
