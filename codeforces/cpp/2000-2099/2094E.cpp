#include <iostream>
#include <vector>

using namespace std;

#define ll long long

ll solve(const int n)
{
    vector<ll> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    return 5LL;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;


        cout << solve(n) << "\n";
    }
}
