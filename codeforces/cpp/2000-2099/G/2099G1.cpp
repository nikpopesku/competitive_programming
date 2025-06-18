#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, k, q, l, r;
    cin >> n >> k >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0; i < q; ++i)
    {
        cin >> l >> r;

        int max_count = 1;

        for (int j = l - 1; j < r; ++j)
        {
            int current_count = 1;
            for (int j_right = j + 1; j_right < r; ++j_right)
            {
                if (a[j_right] - a[j] ==  abs(j_right - j))
                {
                    ++current_count;
                }
            }

            max_count = max(max_count, current_count);
        }

        cout << r - l + 1 - max_count << "\n";
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
