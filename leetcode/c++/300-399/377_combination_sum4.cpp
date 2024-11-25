#include <iostream>
#include <vector>
#include <climits>

using std::vector;

class Solution {
public:
    int combinationSum4(const vector<int>& nums, int target) {
        vector dp (target+1, 0);
        dp[0] = 1;

        for (int i = 0; i <= target; i++) {
            for (auto& n: nums) {
                if (i >= n) {
                    dp[i] += dp[i-n];
                }
            }
        }

        return dp[target];
    }
};

int main() {
    auto s = Solution();
    std::cout << s.combinationSum4({9}, 3) << std::endl;
}
