#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(const string &s, const string &t) {
        std::vector<std::vector<int>> dp;
        const auto m = s.size();
        const auto n = t.size();
        dp.resize(m + 1, std::vector(n + 1, 0));


        dp[0][0] = 1;
        for (int i = 0; i <= m; i++) dp[i][n] = 0;
        for (int j = 0; j <= n; j++) dp[m][j] = 1;

        for (auto i = m-1; i >= 0; i--) {
            for (auto j = n-1; j >= 0; j--) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i+1][j+1] + dp[i][j+1];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }

        return dp[0][0];
    }
};


int main() {
    auto s = Solution();
    cout << s.numDistinct("rabbbit", "rabbit") << endl;
}
