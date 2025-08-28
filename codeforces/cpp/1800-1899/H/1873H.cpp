#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    int u, v;
    map<int, vector<int>> adj;

    for (int i = 0; i < n; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++) { solve(); }
}
