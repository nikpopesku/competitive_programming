#include <iostream>
#include <vector>

#define  ll long long

using namespace std;

ll find(const ll value, const vector<ll>& a)
{
    ll left = 0, right = static_cast<ll>(a.size()) - 1;

    while (left + 1 < right)
    {
        if (const ll m = left + (right - left) / 2; a[m] > value)
        {
            right = m - 1;
        }
        else
        {
            left = m;
        }
    }

    return a[right] == value ? right : left;
}

void solve()
{
    ll n, k, q, value;
    cin >> n >> k >> q;
    vector a(k + 1, 0LL);
    vector b(k + 1, 0LL);

    for (ll i = 1; i <= k; ++i)
    {
        cin >> a[i];
    }

    for (ll i = 1; i <= k; ++i)
    {
        cin >> b[i];
    }

    for (ll i = 0; i < q; ++i)
    {
        cin >> value;

        const ll index = find(value, a);
        long long response = b[index];

        if (index < a.size() - 1)
        {
            response += (value - a[index]) / (a[index + 1] - a[index]) * (b[index + 1] - b[index]);
        }

        cout << response << " ";
    }

    cout << "\n";
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}
