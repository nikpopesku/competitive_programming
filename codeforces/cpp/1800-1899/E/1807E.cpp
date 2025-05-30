#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector partial_sum(n + 1, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        partial_sum[i + 1] = partial_sum[i] + a[i];
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
