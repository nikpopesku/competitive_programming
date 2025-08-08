#include <iostream>

using namespace std;

constexpr int VAL = 1e5;

void solve()
{
    int r;
    cin >> r;

    // int a[VAL];
    // for (int& i : a) i = 0;
    int x = r;
    int y = 0;

    int response = 0;

    while (x > 0)
    {
        const int val = x * x + y * y;
        if (val >= r * r && val < (r + 1) * (r + 1))
        {
            ++response;
            ++y;
            continue;
        }

        if (val >= (r + 1) * (r + 1))
        {
            --x;
            --y;
            continue;
        }

        ++y;
    }

    cout << 4 * response << "\n";
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
