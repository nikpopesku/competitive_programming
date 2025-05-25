#include <iostream>
#include <vector>

using namespace std;

#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector cn(30, 0LL);
    vector<ll> v(n);

    for (ll i = 0; i < n; ++i)
    {
        cin >> v[i];

        for (ll j = 0; j < 30; ++j)
        {
            cn[j] += (v[i] >> j) & 1;
        }
    }

    ll abs_max = 0;

    for (ll i = 0; i < n; ++i)
    {
        ll cur_max = 0;

        for (ll j = 0; j < 30; ++j)
        {
            if (const ll val = (v[i] >> j) & 1; val == 1LL)
            {
                cur_max += (n - cn[j]) * (1 << j);
            }
            else
            {
                cur_max += cn[j] * (1 << j);
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
