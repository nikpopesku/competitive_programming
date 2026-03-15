#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Bit {
public:
    explicit Bit(const int sz): n(sz), tree(n+1, 0) {}

    void update(int index, const int delta) {
        while (index <= n) {
            tree[index] += delta;
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
    int reversePairs(vector<int>& nums) {
        vector<int> sorted{nums.begin(), nums.end()};
        ranges::sort(sorted);
        sorted.erase(ranges::unique(sorted).begin(), sorted.end());
    }
};

int main() {
    vector nums = {1, 3, 2, 3, 1};
    auto na = Solution();
    cout << na.reversePairs(nums) << "\n"; //2

    vector nums2 = {2, 4, 3, 5, 1};
    cout << na.reversePairs(nums2) << "\n"; //3
}
