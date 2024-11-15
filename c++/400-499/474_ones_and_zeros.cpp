#include <iostream>
#include <vector>
#include <algorithm>


using std::cout, std::endl, std::string, std::vector, std::count;
using std::max;

class Solution {
public:
    int findMaxForm(const vector<string> &strs, const int m, const int n) {
        vector dp(strs.size() + 1, vector(m + 1, vector(n + 1, 0)));
        int max_value = 0;

        for (int i = 1; i <= strs.size(); i++) {
            int zeros = 0;
            int ones = 0;
            for (const char s0 : strs[i-1]) {
                if (s0 == '1') ones++;
                if (s0 == '0') zeros++;
            }

            for (int j = m; j >= 0; j--) {
                for (int k = n; k >= 0; k--) {
                    if (j + zeros <= m and k + ones <= n) {
                        dp[i][j][k] = max(dp[i][j + zeros][k + ones] + 1, dp[i - 1][j][k]);
                        if (dp[i][j][k] > max_value) {
                            max_value = dp[i][j][k];
                        }
                    } else {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
            }
        }

        return max_value;
    }
};

int main() {
    auto s = Solution();
    cout << s.findMaxForm({"10", "0001", "111001", "1", "0"}, 5, 3) << endl;
}
