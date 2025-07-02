#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    explicit NumArray(vector<int> &nums) : nums(nums) {
        bit.assign(nums.size(), 0);

        for (size_t i = 0; i < bit.size(); i++)
            add(i, nums[i]);
    }

    void update(int idx, const int val) {
        const int delta = val - nums[idx];

        nums[idx] = val;

        for (; static_cast<size_t>(idx) < bit.size(); idx = idx | (idx + 1)) {
            bit[idx] += delta;
        }
    }

    [[nodiscard]] int sumRange(const int l, const int r) const {
        return sum(r) - sum(l - 1);
    }

private:
    vector<int> bit;
    vector<int> &nums;


    void add(size_t idx, const int delta) {
        for (; idx < nums.size(); idx = idx | (idx + 1))
            bit[idx] += delta;
    }


    [[nodiscard]] int sum(int r) const {
        int ret = 0;

        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];

        return ret;
    }
};


int main() {
    vector v = {1, 3, 5};
    auto na = NumArray(v);
    cout << na.sumRange(0, 2) << "\n";

    na.update(1, 2);

    cout << na.sumRange(0, 2) << "\n";
}
