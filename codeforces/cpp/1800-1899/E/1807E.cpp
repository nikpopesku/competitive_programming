#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, value;
    cin >> n;
    vector<int> a(n);
    vector partial_sum(n + 1, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        partial_sum[i + 1] = partial_sum[i] + a[i];
    }

    int l = 0, r = n - 1;

    while (l < r)
    {
        const int m = l + (r - l) / 2;

        cout << "? " << m - l + 1 << " ";

        for (int i = l; i <= m; ++i)
        {
            cout << i + 1 << " ";
        }

        cout << endl;

        cin >> value;

        if (value > partial_sum[m + 1])
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }

    cout << "! " << l + 1;
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
