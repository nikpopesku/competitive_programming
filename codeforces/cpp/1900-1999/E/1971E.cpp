#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int find(const int value, const vector<int>& a, const int& n)
{
    int left = 0, right = static_cast<int>(a.size()) - 1;

    while (left + 1 < right)
    {
        if (const int m = left + (right - left) / 2; a[m] > value)
        {
            right = m - 1;
        }
        else
        {
            left = m;
        }
    }

    return a[right] == value ? right : left;
}

void solve()
{
    int n, k, q, value;
    cin >> n >> k >> q;
    vector a(k + 1, 0);
    vector b(k + 1, 0);

    for (int i = 1; i <= k; ++i)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= k; ++i)
    {
        cin >> b[i];
    }

    for (int i = 0; i < q; ++i)
    {
        cin >> value;

        const int index = find(value, a, n);
        int response = a[index];

        if (index < a.size() - 1)
        {
            response += static_cast<int>(trunc(
                static_cast<float>(value - a[index]) / static_cast<float>(a[index + 1] - a[index]) * static_cast<float>(
                    b[index + 1] - b[index])));
        }

        cout << response << " ";
    }

    cout << "\n";
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
