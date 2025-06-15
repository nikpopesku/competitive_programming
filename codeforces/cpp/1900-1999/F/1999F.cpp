#include <iostream>

using namespace std;

#define ll long long
constexpr
ll MODULO = 10e9 + 7;

void solve()
{
    int n, k, value;
    cin >> n >> k;
    ll zeros = 0;
    ll answer1 = 1;
    ll answer2 = 1;

    for (int i = n; i > k; --i) answer1 *= i;


    for (int i = 0; i < n; ++i)
    {
        cin >> value;
        if (value == 0) ++zeros;
    }

    for (ll i = zeros; i > zeros - (k + 1) / 2; --i) answer2 *= i;

    cout << (answer1 - answer2) % MODULO << "\n";
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
