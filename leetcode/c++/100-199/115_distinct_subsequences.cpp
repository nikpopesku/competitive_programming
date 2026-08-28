#include <string>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

class Solution {
public:
    ll numDistinct(string s, string t) {
        const ll n = static_cast<ll>(s.size());
        const ll m = static_cast<ll>(t.size());

        vector dp(n + 1, vector<ll>(m + 1, 0));
        for (ll i = 0; i <= n; ++i) dp[i][0] = 1;
        for (ll i = 1; i <= m; ++i) dp[0][i] = 0;

        for (ll i = 1; i <= n; ++i) {
            for (ll j = 1; j <= m; ++j) {
                if (s[i - 1] == t[j - 1]) {
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
    cout << s.numDistinct("babgbag", "bag") << endl;
}
