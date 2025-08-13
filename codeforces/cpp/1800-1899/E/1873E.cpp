#include <iostream>
#include <vector>

#define ll long long

using namespace std;

bool calc(const vector<ll>& v, const ll& m, const ll& x)
{
    ll response = 0;

    for (const ll i : v)
    {
        if (m > i) response += m - i;
        if (response > x) return false;
    }


    return response <= x;
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
        if (const ll m = left + (right - left) / 2; calc(v, m, x))
        {
            left = m;
        }
        else
        {
            right = m - 1;
        }
    }

    cout << (calc(v, right, x) ? right : left) << "\n";
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
