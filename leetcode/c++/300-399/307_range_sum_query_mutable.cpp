#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    explicit NumArray(const vector<int> &nums) : n(static_cast<int>(nums.size())), tree(n + 1, 0) {
        for (int i = 0; i < n; ++i) {
            update(i, nums[i]);
        }
    }

    void update(int index, const int val) {
        const int delta = val - sumRange(index, index);
        ++index;

        while (index <= n) {
            tree[index] += delta;
            index += index & -index;
        }
    }


    [[nodiscard]] int sumRange(const int left, const int right) const {
        return query(right) - (left > 0 ? query(left - 1) : 0);
    }

private:
    int n;
    vector<int> tree;

    [[nodiscard]] int query(int index) const {
        ++index;
        int sum = 0;

        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }

        return sum;
    }
};


int main() {
    const vector v = {1, 3, 5};
    auto na = NumArray(v);
    cout << na.sumRange(0, 2) << "\n";

    na.update(1, 2);

    cout << na.sumRange(0, 2) << "\n";
}
