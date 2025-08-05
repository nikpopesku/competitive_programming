#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, k, q, value;
    cin >> n >> k >> q;
    vector a(k, 0);
    vector b(k, 0);

    for (int i = 0; i < k; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0; i < k; ++i)
    {
        cin >> b[i];
    }

    for (int i = 0; i < q; ++i)
    {
        cin >> value;
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
}
