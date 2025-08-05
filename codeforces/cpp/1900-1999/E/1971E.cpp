#include <iostream>
#include <vector>
#include <chrono>
#include <random>

typedef long long ll;
using namespace std;

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;
    vector<long long> a(k + 1), b(k + 1);
    a[0] = 0;
    b[0] = 0;
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < q; i++)
    {
        long long c;
        cin >> c;
        int l = 0, r = k;
        while (l <= r)
        {
            if (const int mid = l + r >> 1; a[mid] > c)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (a[r] == c)
        {
            cout << b[r] << " ";
            continue;
        }
        const long long ans = b[r] + (c - a[r]) * (b[r + 1] - b[r]) / (a[r + 1] - a[r]);
        cout << ans << " ";
    }
    cout << endl;
}

int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
