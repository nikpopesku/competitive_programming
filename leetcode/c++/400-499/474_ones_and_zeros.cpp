#include <iostream>
#include <vector>
#include <algorithm>


using std::cout, std::endl, std::string, std::vector, std::count;
using std::max;

class Solution {
public:
    int findMaxForm(const vector<string> &strs, const int m, const int n) {
        vector dp(m + 1, vector(n + 1, 0));

        for (int i = 0; i < strs.size(); i++) {
            int zeros = 0;
            int ones = 0;
            for (const char s0 : strs[i]) {
                if (s0 == '1') ones++;
                if (s0 == '0') zeros++;
            }

            for (int j = m; j >= zeros; j--) {
                for (int k = n; k >= ones; k--) {
                    dp[j][k] = max(dp[j - zeros][k - ones] + 1, dp[j][k]);
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    auto s = Solution();
    cout << s.findMaxForm({"10", "0001", "111001", "1", "0"}, 5, 3) << endl;
}
