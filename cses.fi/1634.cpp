#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n, -1);
    vector<int> dp(x + 1, -1);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) cin >> coins[i];
    for (auto &coin: coins) dp[coin] = 1;

    for (int i = 0; i < dp.size(); ++i) {
        for (auto &c: coins) {
            if (i - c >= 0) {
                int current = dp[i] == -1 ? 1'000'000'000 : dp[i];
                dp[i] = min(current, dp[i - c] + 1);
            }
        }
    }

    cout << dp[x] << "\n";
}