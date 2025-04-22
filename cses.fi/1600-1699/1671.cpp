#include<iostream>
#include<vector>
#include <queue>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    constexpr ll BIG = 1e18;

    int n, m;
    cin >> n >> m;
    int a, b;
    ll c;
    vector adj_list(n, vector<pair<int, ll>>(0));
    vector dist(n, BIG);
    dist[0] = 0;

    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        adj_list[a - 1].emplace_back(b - 1, c);
    }

    using T = pair<int, ll>;
    priority_queue<T, vector<T>, greater<T>> pq;

    pq.emplace(0, 0);

    while (!pq.empty())
    {
        auto const [city, cdist] = pq.top();
        pq.pop();
        if (cdist != dist[city]) continue;

        for (const auto& [neighbour_city, neighbour_distance] : adj_list[city])
        {
            if (cdist + neighbour_distance < dist[neighbour_city])
            {
                dist[neighbour_city] = cdist + neighbour_distance;
                pq.emplace(neighbour_city, dist[neighbour_city]);
            }
        }
    }

    for (int i = 0; i < n; ++i) cout << dist[i] << " ";
}
