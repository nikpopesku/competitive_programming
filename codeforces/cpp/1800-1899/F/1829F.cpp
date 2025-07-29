#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, m, a, b;
    cin >> n >> m;
    int degree[200];
    for (int & i : degree) i = 0;

    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        ++degree[a];
        ++degree[b];
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
