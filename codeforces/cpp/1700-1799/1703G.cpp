#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), partial_sum(n + 1, 0);

    int response = 0;


    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        partial_sum[i + 1] = partial_sum[i] + a[i];
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
