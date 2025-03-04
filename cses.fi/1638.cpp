#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int MOD = 1e9 + 7;
    int n;
    cin >> n;
    vector<vector<char>> vc(n);
    vector<vector<int>> dp(n);
    for (int i = 0; i < n; ++i) {
        vc[i].resize(n);
        dp[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> vc[i][j];
            dp[i][j] = 0;
        }
    }

    dp[0][0] = vc[0][0] != '*' ? 1 : 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > 0 and vc[i - 1][j] != '*') {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }
            if (j > 0 and vc[i][j - 1] != '*') {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    cout << dp[n - 1][n - 1] << "\n";
}