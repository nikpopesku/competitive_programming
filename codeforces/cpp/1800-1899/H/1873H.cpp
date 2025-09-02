#include <iostream>
#include <vector>
#include <map>

using namespace std;

int dfsEntryNode(const int node, const int parent, map<int, vector<int>> adj, vector<bool> visited)
{
    visited[node] = true;

    for (const int neighbour : adj[node])
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

int dfsDistance(int node, int entryNode, map<int, vector<int>> adj, vector<bool> visited)
{
    visited[node] = true;
    int distance = 0;

    if (node == entryNode)
    {
        return distance;
    }

    for (const int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            distance = 1 + dfsDistance(neighbour, entryNode, adj, visited);
        }
    }

    return distance;
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

    vector visited(n + 1, false);
    const int entryNode = dfsEntryNode(a, -1, adj, visited);
    int marcelDistance, valeriuDistance;

    visited.assign(n + 1, false);
    if (entryNode == a)
    {
        marcelDistance = 0;
    }
    else
    {
        marcelDistance = dfsDistance(a, entryNode, adj, visited);
    }

    visited.assign(n + 1, false);
    if (entryNode == b)
    {
        valeriuDistance = 0;
    }
    else
    {
        valeriuDistance = dfsDistance(b, entryNode, adj, visited);
    }

    if (valeriuDistance < marcelDistance)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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
