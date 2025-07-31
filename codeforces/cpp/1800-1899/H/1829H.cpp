#include "bits/stdc++.h"
using namespace std;

constexpr int mod = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector dp(n + 1, vector(1 << 6, 0));

    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];

        for (int mask = 0; mask < 1 << 6; ++mask)
        {
            dp[i][mask] = (dp[i][mask] + dp[i - 1][mask]) % mod;
            dp[i][mask & a[i]] = (dp[i][mask & a[i]] + dp[i - 1][mask]) % mod;
        }

        dp[i][a[i]] = (dp[i][a[i]] + 1) % mod;
    }

    int answer = 0;

    for (int mask = 0; mask < 1 << 6; ++mask)
    {
        if (__builtin_popcount(mask) == k)
        {
            answer = (answer + dp[n][mask]) % mod;
        }
    }

    cout << answer << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
