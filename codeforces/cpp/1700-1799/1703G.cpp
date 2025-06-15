#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    int response = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
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
