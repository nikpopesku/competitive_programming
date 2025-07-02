#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    explicit NumArray(const vector<int> &nums) : nums(nums) {
        n = static_cast<int>(nums.size());
        bit.assign(n, 0);

        for (size_t i = 0; i < bit.size(); i++)
            add(i, nums[i]);
    }

    void add(size_t idx, const int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }

    void update(int idx, const int val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += val - nums[idx];
        nums[idx] = val;
    }

    [[nodiscard]] int sumRange(const int l, const int r) const {
        return sum(r) - sum(l - 1);
    }

    [[nodiscard]] int sum(int r) const {
        int ret = 0;

        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];

        return ret;
    }

private:
    vector<int> bit = {};
    vector<int> nums = {};
    int n;
};


int main() {
    const vector v = {1, 3, 5};
    auto na = NumArray(v);
    cout << na.sumRange(0, 2) << "\n";

    na.update(1, 2);

    cout << na.sumRange(0, 2) << "\n";
}
