#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

#define ll long long

constexpr ll inf = 1e18;

auto solve()
{
    int n, m;
    cin >> n >> m;
    int u, v, w;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<ll> slow(n + 1);

    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    for (int i = 1; i <= n; ++i) cin >> slow[i];
    priority_queue<tuple<ll, ll, ll>> q;
    q.emplace(0LL, 0LL, slow[0]);

    vector dist(n, vector(n, inf));
    vector visited(n, vector(n, false));


    while (!q.empty())
    {
        auto [time, city, slow_factor] = q.top();
        q.pop();
        visited[city][slow_factor] = true;

        for (auto [adj_city, distance] : adj[city])
        {
            auto new_slow_factor = min(slow_factor, slow[adj_city]);

            if (dist[adj_city][slow_factor] > dist[adj_city][new_slow_factor] + time * new_slow_factor)
            {
                dist[adj_city][slow_factor] = dist[adj_city][new_slow_factor] + time * new_slow_factor;
                q.emplace(-dist[adj_city][new_slow_factor] + time * new_slow_factor, adj_city, new_slow_factor);
            }
        }
    }

    auto response = inf;

    for (auto value : dist[n - 1])
    {
        response = min(response, value);
    }

    cout << response << "\n";
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
