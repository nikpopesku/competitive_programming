#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

auto solve()
{
    int n, m;
    cin >> n >> m;
    int u, v, w;
    vector<map<int, int>> adj_list(n + 1);
    vector<int> slow(n + 1);

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

    for (int i = 1; i <= n; ++i) cin >> slow[i];
    priority_queue<pair<int, int>> q;
    q.emplace(0, 1);
    map<int, int> times;

    while (!q.empty())
    {
        auto [minus_weight, city] = q.top();
        q.pop();

        if (times.contains(city) and times[city] < -1 * minus_weight)
        {
            continue;
        }

        times[city] = -1 * minus_weight;

        for (auto [new_city, new_weight] : adj_list[city])
        {
            int new_total_path_weight = -new_weight * slow[city] + minus_weight;
            if (times.contains(new_city) and new_total_path_weight < -1 * times[new_city])
            {
                continue;
            }
            q.emplace(new_total_path_weight, new_city);
        }
    }

    cout << times[n] << "\n";
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
