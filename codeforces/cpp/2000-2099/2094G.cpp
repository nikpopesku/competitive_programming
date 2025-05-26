#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    deque<int> dq_normal, dq_reversed;
    int q, type, value, total_sum = 0;
    int normal_r = 0, reverse_r = 0, cnt = 0;
    cin >> q;

    while (q--)
    {
        cin >> type;

        if (type == 3)
        {
            cin >> value;
            ++cnt;
            total_sum += value;

            dq_normal.push_back(value);
            normal_r = value * cnt;

            dq_reversed.push_front(value);
            reverse_r += value;
            reverse_r += total_sum;
        }
        else if (type == 2)
        {
            swap(normal_r, reverse_r);
            swap(dq_normal, dq_reversed);
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
