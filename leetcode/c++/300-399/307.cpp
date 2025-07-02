#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    explicit NumArray(const vector<int>& nums): nums(nums) {
        bit.assign(nums.size(), 0);

        for (int i = 0; i < nums.size(); ++i) {
            add_delta(i, nums[i]);
        }
    }

    void update(int i, int val) {
        const int delta = val - nums[i];

        nums[i] = val;

        add_delta(i, delta);
    }

    int sumRange(const int left, const int right) {
        return sum(right) - sum(left - 1);
    }
private:
    vector<int> bit;
    vector<int> nums;

    void add_delta(int i, const int delta) {
        while (i < nums.size()) {
            bit[i] += delta;

            i = i | (i + 1);
        }
    }

    int sum(int i) {
        int response = 0;

        while (i >= 0) {
            response += bit[i];

            i = (i & (i + 1)) - 1;
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
