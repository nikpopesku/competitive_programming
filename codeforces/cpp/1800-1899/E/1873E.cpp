#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll calc(vector<ll>& v, const ll& m)
{
    ll response = 0;

    for (const ll i : v)
    {
        if (m > i)
        {
            response += m - i;
        }
    }


    return response;
}

void solve()
{
    ll n, x;
    cin >> n >> x;
    vector v(n, 0LL);

    for (ll i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    ll left = 1, right = 1e18;

    while (left + 1 < right)
    {
        const ll m = left + (right - left) / 2;
        ll value = calc(v, m);

        if (value > x)
        {
            right = m - 1;
        }
        else
        {
            left = m;
        }
    }

    cout << (calc(v, right) <= x ? right : left) << "\n";
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
