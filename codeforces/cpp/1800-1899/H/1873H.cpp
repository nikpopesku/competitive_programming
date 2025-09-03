#include <iostream>
#include <vector>
#include <map>

using namespace std;

constexpr int N = 200005;

vector<int> adj[N];

int dfsEntryNode(const int node, const int parent, vector<bool>& visited)
{
    visited[node] = true;

    for (const int neighbour : adj[node])
    {
        if (neighbour == parent) continue;;

        if (visited[neighbour])
        {
            return neighbour;
        }

        const int entryNode = dfsEntryNode(neighbour, node, visited);

        if (entryNode != -1)
        {
            return entryNode;
        }
    }

    return -1;
}

int dfsDistance(const int node, const int entryNode, vector<bool> visited)
{
    visited[node] = true;
    int distance = N;

    if (node == entryNode)
    {
        return 1;
    }

    for (const int neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            int dist = 1 + dfsDistance(neighbour, entryNode, visited);
            distance = min(distance, dist);
        }
    }

    return distance;
}

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    int u, v;

    for (int i = 0; i < n; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector visited(n + 1, false);
    const int entryNode = dfsEntryNode(b, -1, visited);
    int marcelDistance, valeriuDistance;

    visited.assign(n + 1, false);
    if (entryNode == a)
    {
        marcelDistance = 0;
    }
    else
    {
        marcelDistance = dfsDistance(a, entryNode, visited);
    }

    visited.assign(n + 1, false);
    if (entryNode == b)
    {
        valeriuDistance = 0;
    }
    else
    {
        valeriuDistance = dfsDistance(b, entryNode, visited);
    }

    if (valeriuDistance < marcelDistance)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
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
