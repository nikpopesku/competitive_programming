#include <iostream>
#include <vector>
#include <map>

using namespace std;

auto solve()
{
    int n, m;
    cin >> n >> m;
    int u, v, w;
    vector<map<int, int>> adj_list(n);
    vector<int> slow(n);

    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        if (adj_list[u].contains(v))
        {
            adj_list[u][v] = min(adj_list[u][v], w);
        }
        else
        {
            adj_list[u][v] = w;
        }
    }

    for (int i = 0; i < n;  ++i) cin >> slow[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
