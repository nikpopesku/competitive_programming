#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> c(n);
    string response = "YES";

    for (int i = 0; i < n; ++i)
    {
        cin >> c[i];
    }

    if (c.size() == 1)
    {
        cout << (c[0] == 1 ? "YES" : "NO") << "\n";
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
