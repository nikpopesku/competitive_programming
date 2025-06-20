#include <iostream>
#include <cmath>

using namespace std;

#define ll long long

void solve()
{
    ll n, val;
    cin >> n;
    ll sum = 0;

    for (ll i = 0; i < n; ++i)
    {
        cin >> val;
        sum += val;
    }

    const double root = sqrt(static_cast<double>(sum));
    cout <<  (floor(root) == ceil(root) ? "YES" : "NO") << "\n";
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
