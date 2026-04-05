#include <iostream>
#include <vector>

using namespace std;

class Bit {
public:
    explicit Bit(const int sz) : n(sz), tree(n + 1, 0) {
    }

    void update(int index) {
        while (index <= n) {
            ++tree[index];
            index += index & -index;
        }
    }

    int query(int index) const {
        int sm = 0;

        while (index > 0) {
            sm += tree[index];
            index -= index & -index;
        }

        return sm;
    }

private:
    int n;
    vector<int> tree;
};

class Solution {
public:
    bool isIdealPermutation(const vector<int> &nums) {
        Bit bt(2000000 + 2);
        const int n = static_cast<int>(nums.size());

        int global = 0;
        int local = 0;

        for (int i = 0; i < n; ++i) {
            if (i < n - 1 && nums[i] > nums[i+1]) {
                ++local;
            }
            global += bt.query(nums[i]);
            bt.update(nums[i]);
        }

        return global > local;
    }
};


int main() {
    auto s = Solution();

    vector<int> v = {1, 0, 2};
    cout << boolalpha << s.isIdealPermutation(v) << '\n';

    vector<int> v2 = {1, 2, 0};
    cout << boolalpha << s.isIdealPermutation(v2) << '\n';
}
