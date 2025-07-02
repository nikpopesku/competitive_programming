#include <vector>

using namespace std;

class NumArray {
public:
    explicit NumArray(const vector<int> &nums): nums(nums) {
    }

    void update(int index, int val) {
    }

    int sumRange(int left, int right) {
    }

private:
    vector<int> nums = {};
};


int main() {
    vector v = {1, 3, 5};
    auto na = NumArray(v);
}
