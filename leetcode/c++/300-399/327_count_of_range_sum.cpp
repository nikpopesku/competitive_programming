#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countRangeSum(const vector<int> &nums, const int lower, const int upper) {
        vector<int> prefix;
        for (int x: nums) {
            prefix.push_back(x);
            prefix.push_back(x - lower);
            prefix.push_back(x - upper);
        }

        ranges::sort(prefix);
        prefix.erase(unique(prefix.begin(), prefix.end()) - prefix.end());
    }
};

int main() {
    auto na = Solution();

    vector v = {-2, 5, -1};
    cout << na.countRangeSum(v, -2, 2) << "\n";

    vector v2 = {0};
    cout << na.countRangeSum(v2, 0, 0) << "\n";
}
