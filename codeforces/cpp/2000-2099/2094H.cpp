#include <bits/stdc++.h>

using namespace std;

#define int long long

int f(int k, const vector<int>& a, const int& l, const int& r)
{
    int ans = 0;

    for (int i = l; i <= r; ++i)
    {
        while (k % a[i] == 0)
        {
            k = k / a[i];
        }

        ans += k;
    }

    return ans;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    int k, l, r;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0; i < q; ++i)
    {
        cin >> k >> l >> r;

        cout << f(k, a, l, r) << "\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
