#include <iostream>
#include <vector>

using namespace std;

int calc(const vector<int>& v, const int& m)
{
    int response = 0;

    int left = 0, right = v.size() - 1;

    while (left < right)
    {
        if (v[left] < v[right])
        {
            response += min(v[right], m) - min(v[left], m);
            ++left;
        } else
        {
            ++right;
            response += min(v[left], m) - min(v[right], m);
        }
    }


    return response;
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

    int left = 1, right = 1e9;

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
