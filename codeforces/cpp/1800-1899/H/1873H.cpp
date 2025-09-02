#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

vector<int> adj[N];
vector<bool> vis(N);

int entry_node = -1;
vector<int> path;

bool dfs1(const int u, const int p)
{
    vis[u] = true;
    for (const auto v : adj[u])
    {
        if (v != p && vis[v])
        {
            entry_node = v;
            return true;
        }


        if (v != p && !vis[v])
        {
            if (dfs1(v, u))
            {
                return true;
            }
        }
    }

    return false;
}

int dfs2(const int u)
{
    vis[u] = true;
    int distbruh = N;
    for (const auto v : adj[u])
    {
        if (v == entry_node)
        {
            return 1;
        }

        if (!vis[v])
        {
            int dist = dfs2(v) + 1;
            distbruh = min(dist, distbruh);
        }
    }
    return distbruh;
}

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(b, -1);
    vis.assign(n + 1, false);
    int distMarcel, distValeriu = 0;

    if (entry_node == a)
    {
        distMarcel = 0;
    }
    else
    {
        distMarcel = dfs2(a);
    }

    vis.assign(n + 1, false);

    if (entry_node == b)
    {
        distValeriu = 0;
    }
    else
    {
        distValeriu = dfs2(b);
    }

    if (distValeriu < distMarcel)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
        vis[i] = false;
    }
}

int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
