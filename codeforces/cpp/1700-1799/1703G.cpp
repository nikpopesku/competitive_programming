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

    for (int i = 0; i < n; ++i)
    {
        long long now = sum;
        for (int j = i; j < min(n, i + 32); ++j)
        {
            int copy = a[j];
            copy >>= j - i + 1;
            now += copy;
        }

        response = max(response, now);

        sum += a[i] - k;
    }

    cout << response << "\n";
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
