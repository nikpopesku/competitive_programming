#include <iostream>
#include <vector>

using namespace std;


void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    long long response = 0, sum = 0;


    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for (int i = -1; i < n; i++)
    {
        long long now = sum;
        for (int j = i + 1; j < min(n, i + 32); j++)
        {
            int copy = a[j];
            copy >>= j - i;
            now += copy;
        }
        response = max(response, now);
        if (i + 1 != n)
        {
            sum += a[i + 1] - k;
        }
    }
    cout << response << endl;
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
