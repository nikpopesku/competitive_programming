#include<bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, x;
    cin >> n >> x;
    vector<ll> coins(n);
    for (ll i = 0; i < n; ++i) cin >> coins[i];
    sort(coins.begin(), coins.end());

    vector<ll> dp(x + 1, 0);
    dp[0] = 1;

    for (auto &coin: coins) {
        if (coin > x) break;

        for (ll sum = coin; sum <= x; ++sum) {
            dp[sum] = (dp[sum] + dp[sum - coin]) % MOD;
        }
    }

    cout << dp[x] << "\n";
}