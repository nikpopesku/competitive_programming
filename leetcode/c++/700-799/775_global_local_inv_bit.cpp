#include <iostream>
#include <vector>

using namespace std;

class Bit {
public:
    explicit Bit(const int sz) : n(sz), tree(n + 1, 0) {
    }

    void update(int index) {
        ++index;
        while (index <= n) {
            ++tree[index];
            index += index & -index;
        }
    }

    [[nodiscard]] int query(int index) const {
        int sm = 0;
        ++index;

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
        const int n = static_cast<int>(nums.size());

        int global = 0;
        int local = 0;

        vector<int> v = nums;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        const int m = static_cast<int>(v.size());
        Bit bt(m);

        for (int i = 0; i < n; ++i) {
            if (i < n - 1 && nums[i] > nums[i + 1]) {
                ++local;
            }
            const int index = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
            global += bt.query(index);
            bt.update(index);
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
