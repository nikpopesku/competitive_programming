#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(const vector<int> &nums1, const vector<int> &nums2) {
        vector dp(nums1.size() + 1, vector(nums2.size() + 1, 0));

        for (size_t i = 1; i <= nums1.size(); i++) {
            for (size_t j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[nums1.size()][nums2.size()];
    }
};


int main() {
    auto s = Solution();
    cout << s.maxUncrossedLines(vector{1, 4, 2}, vector{1, 2, 4}) << endl;
}
