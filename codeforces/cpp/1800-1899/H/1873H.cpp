#include <iostream>
#include <vector>
#include <map>

using namespace std;

int dfsEntryNode(int node, int parent, map<int, vector<int>> adj, vector<bool> visited)
{
    for (const int neighbour: adj[node])
    {
        if (neighbour == parent) continue;;

        if (visited[neighbour])
        {
            return visited[neighbour];
        }

        if (dfsEntryNode(neighbour, node, adj, visited))
        {
            return true;
        }
    }

    return false;
}

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

    vector visited(n, false);
    int entryNode = dfsEntryNode(a, -1);

    cout << "YES\n";
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (int i = 1; i <= tt; i++) { solve(); }
}
