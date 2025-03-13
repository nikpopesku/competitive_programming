#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int MOD = 1e9 + 7;
    int n, m;
    cin >> n >> m;
    vector<ll> num(n);
    for (int i = 0; i < n; ++i) cin >> num[i];

    vector<vector<ll>> dp(n, vector<ll>(m + 1, 0));

    for (int i = 0; i < n; ++i) {
        if (num[i] > 0 and i > 0) {
            dp[i][num[i]] = (dp[i - 1][num[i] - 1] + dp[i - 1][num[i]] + dp[i - 1][num[i] + 1]) % MOD;
        }

        if (num[i] > 0 and i == 0) {
            dp[i][num[i]] = 1;
        }

        if (num[i] == 0 and i > 0) {
            dp[i][num[i - 1] + 1] = dp[i - 1][num[i - 1]];
            dp[i][num[i - 1]] = dp[i - 1][num[i - 1]];
            dp[i][num[i - 1] - 1] = dp[i - 1][num[i - 1]];
        }

        if (num[i] == 0 and i == 0) {
            for (int j = 0; j <= m; ++j) dp[i][j] = 1;
        }
    }

    cout << dp[n - 1][num[n - 1]] << "\n";
}