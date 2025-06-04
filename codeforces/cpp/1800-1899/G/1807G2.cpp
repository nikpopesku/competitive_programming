#include "bits/stdc++.h"
using namespace std;

#define int long long

void solve()
{
    int n;
    cin >> n;
    vector a(n, 0);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    if (a[0] != 1)
    {
        cout << "NO\n";
        return;
    }
    vector dp(5005, 0);
    dp[1] = 1;

    for (int i = 1; i < n; ++i)
    {
        if (!dp[a[i]])
        {
            cout << "NO\n";
            return;
        }

        for (int j = 5000; j >= a[i]; --j)
        {
            if (dp[j - a[i]])
            {
                dp[j] = 1;
            }
        }
    }

    cout << "YES\n";
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
