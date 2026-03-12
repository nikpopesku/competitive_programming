#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) : tree(nums.size() + 1, 0), n(nums.size()) {
        for (int i = 0; i < n; ++i) {
            update(i, nums[i]);
        }
    }

    void update(int index, int val) {
        ++index;
        while (index <= n) {
            tree[index] += val;
            index += index & -index;
        }
    }

    int sumRange(int left, int right) {
    }
private:
    vector<int> tree;
    int n;
};


int main() {
    const vector v = {1, 3, 5};
    auto na = NumArray(v);
    cout << na.sumRange(0, 2) << "\n";

    na.update(1, 2);

    cout << na.sumRange(0, 2) << "\n";
}
