#include <iostream>
#include <vector>

using namespace std;

#define ll long long

void solve()
{
    ll n, q, l, r, k;
    cin >> n >> q;
    vector<ll> vc(n);
    vector partial_sum(n + 1, 0LL);

    for (ll i = 0; i < n; ++i)
    {
        cin >> vc[i];
        partial_sum[i + 1] = partial_sum[i] + vc[i];
    }

    for (ll i = 0; i < q; ++i)
    {
        cin >> l >> r >> k;
        cout << ((partial_sum[r] - partial_sum[l - 1] + (r - l + 1) * k) % 2 == 1 ? "YES" : "NO") << "\n";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0LL;
}
