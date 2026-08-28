#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        const int n = static_cast<int>(s.size());
        const int m = static_cast<int>(t.size());

        vector dp(n + 1, vector(m + 1, 0));
        for (int i = 0; i < n; ++i) dp[i][0] = 1;
        for (int i = 0; i < m; ++i) dp[0][i] = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][m];
    }
};


int main() {
    auto s = Solution();
    cout << s.numDistinct("rabbbit", "rabbit") << endl;
}
