#include <iostream>
#include <vector>

using namespace std;

#define int long long

void solve()
{
    int n, q, l, r, k;
    cin >> n >> q;
    vector<int> vc(n);
    vector<int> partial_sum(n + 1, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> vc[i];
        partial_sum[i + 1] = partial_sum[i] + vc[i];
    }

    for (int i = 0; i < q; ++i)
    {
        cin >> l >> r >> k;
    }

    cout << (partial_sum[r] - partial_sum[l - 1] + (r - l - 1) * k % 2 == 1 ? "YES" : "NO") << "\n";
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
