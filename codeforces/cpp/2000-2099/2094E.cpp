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
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
