#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Bit {
public:
    explicit Bit (const int sz): n(sz), tree(sz + 1, 0) {

    }

    void update(int index) {
        while (index <= n) {
            ++tree[index];
            index += index & -index;
        }
    }
private:
    int n;
    vector<int> tree;
};

class Solution {
public:
    int countRangeSum(const vector<int> &nums, const int lower, const int upper) {
        vector<int> prefix;
        for (int x: nums) {
            prefix.push_back(x);
            prefix.push_back(x - lower);
            prefix.push_back(x - upper);
        }

        sort(prefix.begin(), prefix.end());
        prefix.erase(unique(prefix.begin(), prefix.end()), prefix.end());
        const int m = static_cast<int>(prefix.size());
        Bit bt(m);
        bt.update(prefix[0]);
    }
};

int main() {
    auto na = Solution();

    vector v = {-2, 5, -1};
    cout << na.countRangeSum(v, -2, 2) << "\n";

    vector v2 = {0};
    cout << na.countRangeSum(v2, 0, 0) << "\n";
}
