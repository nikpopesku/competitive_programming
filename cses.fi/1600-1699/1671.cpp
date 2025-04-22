#include<iostream>
#include<vector>
#include <queue>

using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    constexpr ll BIG = 1e14;

    int n, m;
    cin >> n >> m;
    int a, b;
    ll c;
    vector adj_list(n, vector<pair<ll, int>>(0));
    vector dist(n, BIG);
    dist[0] = 0;

    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        adj_list[a - 1].emplace_back(c, b - 1);
    }

    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<T>> pq;

    pq.emplace(0, 0);

    while (!pq.empty())
    {
        auto const [cdist, city] = pq.top();
        pq.pop();
        if (cdist != dist[city]) continue;

        for (const auto& [neighbour_distance, neighbour_city] : adj_list[city])
        {
            if (cdist + neighbour_distance < dist[neighbour_city])
            {
                dist[neighbour_city] = cdist + neighbour_distance;
                pq.emplace(dist[neighbour_city], neighbour_city);
            }
        }
    }

    for (int i = 0; i < n; ++i) cout << dist[i] << " ";
}
