#include <iostream>
#include <vector>

using namespace std;

int calc(vector<int>& v, int m)
{
    return 5;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector v(n + 2, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> v[i + 1];
    }

    int left = 1, right = 10e9;

    while (left < right)
    {
        const int m = left + (right - left) / 2;

        v[0] = m;
        v[n + 1] = m;

        if (calc(v, m) > x)
        {
            right = m - 1;
        }
        else
        {
            left = m;
        }
    }

    cout << left << "\n";
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
