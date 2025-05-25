#include <iostream>
#include <vector>

using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;
    vector cn(30, 0);
    vector<ll> v(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];

        for (int j = 0; j < 30; ++j)
        {
            cn[j] += (v[i] >> j) & 1;
        }
    }

    ll abs_max = 0;

    for (int i = 0; i < n; ++i)
    {
        ll cur_max = 0;

        for (int j = 0; j < 30; ++j)
        {
            if (ll val = (v[i] >> j) & 1; val == 1)
            {
                cur_max += (n - cn[j]) * (val << j);
            }
            else
            {
                cur_max += cn[j] * (val << j);
            }
        }

        abs_max = max(abs_max, cur_max);
    }

    cout << abs_max << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
