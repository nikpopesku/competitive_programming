#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>

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

    for (int i = 0; i < n; ++i) cin >> slow[i];
    priority_queue<pair<int, int>> q;
    q.emplace(0, 0);
    set<int> visited;
    long long response = 0;


    while (!q.empty())
    {
        auto [minus_weight, city] = q.top();
        q.pop();

        if (visited.contains(city)) continue;

        visited.insert(city);

        if (city == n - 1)
        {
            response = -minus_weight;
            break;
        }

        for (auto [new_city, new_weight] : adj_list[city])
        {
            if (visited.contains(new_city)) continue;
            q.emplace(-new_weight * slow[city] + minus_weight, new_city);
        }
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
