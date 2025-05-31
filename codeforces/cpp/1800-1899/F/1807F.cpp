#include <iostream>
#include <set>

using namespace std;

void solve()
{
    int n, m, i1, j1, i2, j2;
    string d;

    cin >> n >> m >> i1 >> j1 >> i2 >> j2;
    cin >> d;
    set<tuple<int, int, string>> visited;

    pair current = {i1, j1};
    int response = -1;

    while (current.first != i2 or current.second != j2)
    {
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
