#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;
    vector dp(s1.length() + 1, vector<int>(s2.length() + 1, 1e9));
    dp[0][0] = 0;

    for (int i = 1; i <= s1.length(); ++i) dp[i][0] = i;
    for (int j = 1; j <= s2.length(); ++j) dp[0][j] = j;

    for (int i = 1; i <= s1.length(); ++i) {
        for (int j = 1; j <= s2.length(); ++j) {
            dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1));
        }
    }

    cout << dp[s1.length()][s2.length()] << "\n";
}