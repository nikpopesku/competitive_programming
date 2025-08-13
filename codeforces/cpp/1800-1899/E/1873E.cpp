#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll calc(vector<ll>& v, const ll& m)
{
    v[0] = m;
    v[v.size() - 1] = m;
    ll response = 0;

    int left = 0, right = v.size() - 1;

    while (left < right)
    {
        if (v[left] < v[right])
        {
            response += min(v[right], m) - min(v[left], m);
            ++left;
        }
        else
        {
            response += min(v[left], m) - min(v[right], m);
            --right;
        }
    }


    return response;
}

void solve()
{
    ll n, x;
    cin >> n >> x;
    vector v(n + 2, 0LL);

    for (ll i = 0; i < n; ++i)
    {
        cin >> v[i + 1];
    }

    ll left = 1, right = 1e9;

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
