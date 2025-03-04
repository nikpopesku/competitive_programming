#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) cin >> coins[i];

    vector<ll> dp(x + 1, 0);
    for (auto &c: coins) if (c <= x) dp[c] = 1;

    for (auto i = 1; i < dp.size(); ++i) {
        for (auto &c: coins) {
            if (i >= c) {
                dp[i] += dp[i - c];
            }
        }
    }

    ll modulo = 10e9 + 7;

    cout << dp[x] % modulo << "\n";
}