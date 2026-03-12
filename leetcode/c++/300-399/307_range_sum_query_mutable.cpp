#include <iostream>
#include <vector>

using namespace std;


class FenwickTree {
public:
    explicit FenwickTree(const vector<int> &nums) : tree(nums.size() + 1, 0), n(nums.size()) {
        for (int i = 0; i < n; ++i) {
            update(i, nums[i]);
        }
    }

    void update(int i, const int delta) {
        ++i;
        while (i <= n) {
            tree[i] += delta;
            i += i & -i;
        }
    }

private:
    vector<int> tree;
    int n;
};

class NumArray {
public:
    NumArray(vector<int> &nums) {
    }

    void update(int index, int val) {
    }

    int sumRange(int left, int right) {
    }
};


int main() {
    const vector v = {1, 3, 5};
    auto na = NumArray(v);
    cout << na.sumRange(0, 2) << "\n";

    na.update(1, 2);

    cout << na.sumRange(0, 2) << "\n";
}
