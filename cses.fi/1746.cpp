#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const ll MOD = 1e9 + 7;
    ll n, m;
    cin >> n >> m;
    vector<ll> num(n);
    for (ll i = 0; i < n; ++i) cin >> num[i];
    vector dp(n, vector<ll>(m + 1, 0));

    if (num[0] > 0) {
        dp[0][num[0]] = 1;
    } else {
        for (ll j = 0; j <= m; ++j) dp[0][j] = 1;
    }

    for (ll i = 1; i < n; ++i) {
        if (num[i] > 0) {
            if (num[i] - 1 >= 1) dp[i][num[i]] = (dp[i][num[i]] + dp[i - 1][num[i] - 1]) % MOD;
            if (num[i] + 1 <= m) dp[i][num[i]] = (dp[i][num[i]] + dp[i - 1][num[i] + 1]) % MOD;
            dp[i][num[i]] = (dp[i][num[i]] + dp[i - 1][num[i]]) % MOD;
        } else {
            for (ll j = 1; j <= m; ++j) {
                if (j - 1 >= 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (j + 1 <= m) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }

    ll response = dp[n - 1][num[n - 1]];

    if (num[n - 1] == 0) {
        response = 0;

        for (ll j = 1; j <= m; ++j) response = (response + dp[n - 1][j]) % MOD;
    }

    cout << response << "\n";
}