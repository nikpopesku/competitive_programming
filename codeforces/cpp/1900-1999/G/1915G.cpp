#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

#define ll long long

constexpr ll inf = 1e18;

auto solve()
{
    ll n, m;
    cin >> n >> m;
    ll u, v, w;
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<ll> slow(n + 1);

    for (ll i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    for (ll i = 1; i <= n; ++i) cin >> slow[i];
    priority_queue<tuple<ll, ll, ll>> q;
    q.emplace(0LL, 1LL, slow[1]);

    vector dist(n + 1, vector(n + 1, inf));
    vector visited(n + 1, vector(n + 1, false));
    dist[1][slow[1]] = 0;


    while (!q.empty())
    {
        auto [time, city, slow_factor_city] = q.top();
        q.pop();

        if (visited[city][slow_factor_city] || dist[city][slow_factor_city] == inf) continue;

        visited[city][slow_factor_city] = true;

        for (auto [adj_city, distance] : adj[city])
        {
            ll new_slow_factor = min(slow_factor_city, slow[adj_city]);

            if (dist[adj_city][new_slow_factor] > dist[city][slow_factor_city] + static_cast<ll>(distance) * static_cast<ll>(slow_factor_city))
            {
                dist[adj_city][new_slow_factor] = dist[city][slow_factor_city] + static_cast<ll>(distance) * static_cast<ll>(slow_factor_city);
                q.emplace(-dist[adj_city][new_slow_factor], adj_city, new_slow_factor);
            }
        }
    }

    auto response = inf;

    for (ll value : dist[n])
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
