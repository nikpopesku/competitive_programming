#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector a(1, 1);
    vector<int> c(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> c[i];
    }

    while (a.size() < c.size())
    {
    }

    string response = "YES";

    for (int i = 0; i < c.size(); ++i)
    {
        if (c[i] != a[i])
        {
            response = "NO";
            break;
        }
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
