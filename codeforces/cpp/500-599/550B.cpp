#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve()
{
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<int> c(n);
    int total_ways = 0;


    for (int i = 0; i < n; ++i) cin >> c[i];

    for (int i = 0; i <= pow(2, n - 1); ++i)
    {
        int j = 0;
        int sum = 0;
        int min_c = 1e9;
        int max_c = 1;


        while (j < n)
        {
            if (i & 1 << j)
            {
                sum += c[j];
                min_c = min(min_c, c[j]);
                max_c = max(max_c, c[j]);
            }
            ++j;
        }

        if (sum >= l && sum <= r and max_c - min_c >= x) ++total_ways;
    }

    cout << total_ways << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
