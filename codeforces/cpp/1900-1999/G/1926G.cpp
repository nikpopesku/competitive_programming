#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector a(n-1, 0);
    string s;

    for (int i = 2; i <= n; ++i)
    {
        cin >> a[i-2];
    }

    cin >> s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
