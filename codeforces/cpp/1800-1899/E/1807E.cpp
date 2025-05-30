#include <iostream>
#include <vector>

using namespace std;

#define ll long long

void solve()
{
    ll n, value;
    cin >> n;
    vector<ll> a(n);
    vector partial_sum(n + 1, 0);

    for (ll i = 0; i < n; ++i)
    {
        cin >> a[i];
        partial_sum[i + 1] = partial_sum[i] + a[i];
    }

    ll l = 0, r = n - 1;

    while (l < r)
    {
        const ll m = l + (r - l) / 2;

        cout << "? " << m - l + 1 << " ";

        for (ll i = l; i <= m; ++i)
        {
            cout << i + 1 << " ";
        }

        cout << endl;

        cin >> value;

        if (value > partial_sum[m + 1] - partial_sum[l])
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }

    cout << "! " << l + 1 << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}
