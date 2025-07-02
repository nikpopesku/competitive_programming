#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    explicit NumArray(const vector<int> &nums) : nums(nums) {
        bit.assign(nums.size(), 0);

        for (size_t i = 0; i < bit.size(); i++) {
            add_delta(i, nums[i]);
        }
    }

    void update(int idx, const int val) {
        const int delta = val - nums[idx];

        nums[idx] = val;

        while (idx < bit.size()) {
            bit[idx] += delta;

            idx = idx | (idx + 1);
        }
    }

    [[nodiscard]] int sumRange(const int l, const int r) const {
        return sum(r) - sum(l - 1);
    }

private:
    vector<int> bit;
    vector<int> nums;


    void add_delta(size_t idx, const int delta) {
        while (idx < nums.size()) {
            bit[idx] += delta;

            idx = idx | (idx + 1);
        }
    }


    [[nodiscard]] int sum(int r) const {
        int response = 0;

        while (r >= 0) {
            response += bit[r];

            r = (r & (r + 1)) - 1;
        }

        return response;
    }
};


int main() {
    const vector v = {1, 3, 5};
    auto na = NumArray(v);
    cout << na.sumRange(0, 2) << "\n";

    na.update(1, 2);

    cout << na.sumRange(0, 2) << "\n";
}
