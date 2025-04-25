#include <iostream>
#include <vector>
#include <queue>

using namespace std;


#define ll long long
using T = pair<ll, int>;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<vector<pair<ll, int>>> dist(n + 1);
    priority_queue<T, vector<T>, greater<>> pq;
    pq.emplace(0, 1);

    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(c, b);
    }

    while (!pq.empty())
    {
        auto [weight, node] = pq.top();
        pq.pop();

        if (dist[node].size() >= k) continue;

        dist[node].emplace_back(weight, node);

        for (const auto& [price, destination] : adj[node])
        {
            ll new_weight = weight + static_cast<ll>(price);
            pq.emplace(new_weight, destination);
        }
    }

    for (auto const& elem : dist[n])
    {
        cout << elem.first << " ";
    }
}
