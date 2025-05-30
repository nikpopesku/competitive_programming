#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, q, l, r, k;
    cin >> n >> q;
    vector<int> vc(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> vc[i];
    }

    for (int i = 0; i < q; ++i)
    {
        cin >> l >> r >> k;
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
