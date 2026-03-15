#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

constexpr int MOD = 1e9 + 7;

class Bit {
public:
    explicit Bit(const int sz) : n(sz), tree(n + 1, 0) {
    }

    void update(int index) {
        while (index <= n) {
            ++tree[index];
            index += index & -index;
        }
    }

    int query(int index) const {
        int sum = 0;

        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }

        return sum;
    }

private:
    int n;
    vector<int> tree;
};

class Solution {
public:
    int createSortedArray(const vector<int> &instructions) {
        const int n = static_cast<int>(instructions.size());
        int response = 0;

        vector<int> sorted{instructions.begin(), instructions.end()};
        ranges::sort(sorted);
        Bit bt(100001);

        for (int i = 0; i < n; ++i) {
            bt.update(instructions[i]);
            int less = bt.query(instructions[i] - 1);
            int greater = i - bt.query(instructions[i]);
            response += min(less, greater);
        }

        return response % MOD;
    }
};

int main() {
    vector nums = {1, 5, 6, 2};
    auto na = Solution();
    cout << na.createSortedArray(nums) << "\n"; //1

    vector nums2 = {1, 2, 3, 6, 5, 4};
    cout << na.createSortedArray(nums2) << "\n"; //3

    vector nums3 = {1, 3, 3, 3, 2, 4, 2, 1, 2};
    cout << na.createSortedArray(nums3) << "\n"; //4
}
