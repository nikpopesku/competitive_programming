#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Bit {
public:
    explicit Bit(const int sz) : n(sz), tree(sz + 1, 0) {
    }

    void update(int index) {
        while (index <= n) {
            ++tree[index];
            index += index & -index;
        }
    }

    [[nodiscard]] int query(int index) const {
        int response = 0;

        while (index > 0) {
            response += tree[index];
            index -= index & -index;
        }

        return response;
    }

private:
    int n;
    vector<int> tree;
};

class Solution {
public:
    int reversePairs(const vector<int> &nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        const int n = static_cast<int>(sorted.size());

        Bit bt(n);
        const int m = static_cast<int>(nums.size());
        int response = 0;

        for (int i = m - 1; i >= 0; --i) {
            response += bt.query(lower_bound(sorted.begin(), sorted.end(), nums[i], [](const int x, const int target) {
                return 2LL * x < target;
            }) - sorted.begin());
            bt.update(lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin() + 1);
        }

        return response;
    }
};


int main() {
    vector nums = {1, 3, 2, 3, 1};
    auto na = Solution();
    cout << na.reversePairs(nums) << "\n"; //2

    vector nums2 = {2, 4, 3, 5, 1};
    cout << na.reversePairs(nums2) << "\n"; //3
}
