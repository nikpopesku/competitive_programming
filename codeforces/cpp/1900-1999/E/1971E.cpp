#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int find(const int value, const vector& a, const int& n)
{
    int left = 0, right = n;

    while (left < right)
    {
        int m = left + (right - left) / 2;

        if (a[m] > value)
        {
            right = m - 1;
        } else
        {
            left = m;
        }
    }

    return left;
}

void solve()
{
    int n, k, q, value;
    cin >> n >> k >> q;
    vector a(k, 0);
    vector b(k, 0);

    for (int i = 0; i < k; ++i)
    {
        cin >> a[i];
    }

    for (int i = 0; i < k; ++i)
    {
        cin >> b[i];
    }

    for (int i = 0; i < q; ++i)
    {
        cin >> value;

        int index = find(value, a, n);
        int response = a[index];

        if (index < n)
        {
            response += trunc((a[index + 1] - a[index]) / (b[index + 1] - b[index]) * (value - a[index]));
        }

        cout << response << "\n";
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
