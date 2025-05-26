#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    deque<int> dq;
    int q, type, value, total_sum = 0;
    int normal_r = 0, reverse_r = 0;
    cin >> q;

    while (q--)
    {
        cin >> type;

        if (type == 3)
        {
            cin >> value;

            dq.push_back(value);
            total_sum += value;
        }
        else if (type == 2)
        {
        }
        else
        {
        }

        cout << normal_r << "\n";
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
