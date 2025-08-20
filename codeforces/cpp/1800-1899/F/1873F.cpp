#include <iostream>
#include <vector>

#define ll long long

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> h(n);
    int max_value = 0;
    long long current_a = 0;

    for (int i = 0; i < n; ++i) cin >> a[i];
    int current_max = a[0] <= k ? 1 : 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> h[i];
        if (i > 0 && h[i - 1] % h[i] == 0 && current_a + a[i] <= k)
        {
            current_a += a[i];
            ++current_max;
        }
        else
        {
            max_value = max(max_value, current_max);
            current_max = a[i] <= k ? 1 : 0;
            current_a = a[i] <= k ? a[i] : 0;
        }
    }

    max_value = max(max_value, current_max);

    cout << max_value << "\n";
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
