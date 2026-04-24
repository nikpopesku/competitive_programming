#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(const vector<int> &nums) {
        const int n = static_cast<int>(nums.size());
        vector<int> ans(2 * n);
        for (int i = 0; i < n; ++i) {
            ans[i] = ans[i + n] = nums[i];
        }

        return ans;
    }
};

int main() {
    auto s = Solution();

    for (vector<int> nums = {1, 2, 1}; const auto e: s.getConcatenation(nums)) cout << e << ' ';
    cout << '\n';
}
