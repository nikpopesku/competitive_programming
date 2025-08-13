#include <iostream>
#include <vector>

using namespace std;

long long calc(vector<int>& v, const int& m)
{
    v[0] = m;
    v[v.size() - 1] = m;
    long long response = 0;

    int left = 0, right = v.size() - 1;

    while (left < right)
    {
        if (v[left] < v[right])
        {
            response += min(v[right], m) - min(v[left], m);
            ++left;
        }
        else
        {
            response += min(v[left], m) - min(v[right], m);
            --right;
        }
    }


    return response;
}

void solve()
{
    long long n, x;
    cin >> n >> x;
    vector v(n + 2, 0);

    for (long long i = 0; i < n; ++i)
    {
        cin >> v[i + 1];
    }

    long long left = 1, right = 1e9;

    while (left + 1 < right)
    {
        const long long m = left + (right - left) / 2;
        long long value = calc(v, m);

        if (value > x)
        {
            right = m - 1;
        }
        else
        {
            left = m;
        }
    }

    cout << (calc(v, right) <= x ? right : left) << "\n";
}

int main()
{
    long long t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}
