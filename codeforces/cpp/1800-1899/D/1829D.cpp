#include <iostream>

using namespace std;

bool calc(const int n, const int m)
{
    if (n < m) return false;
    if (n == m) return true;

    if (n % 3 == 0)
    {
        return calc(n * 2 / 3, m) || calc(n / 3, m);
    }

    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    cout << (calc(n, m) ? "YES\n" : "NO\n");
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
