#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

#define ll long long

ll INF = numeric_limits<ll>::max() / 2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A, B, C;

    cin >> N >> M;
    vector<vector<pair<int, int>>> adj(N + 1);
    vector self_loop(N + 1, INF);
    vector min_walk(N + 1, -1LL);

    for (int i = 0; i < M; ++i)
    {
        cin >> A >> B >> C;
        if (B == A)
        {
            self_loop[A] = min(self_loop[A], static_cast<ll>(C));
        }
        else
        {
            adj[A].emplace_back(C, B);
        }
    }


    for (int start_town = 1; start_town <= N; ++start_town)
    {
        priority_queue<pair<ll, int>> pq;
        vector dist(N + 1, INF);
        ll current_min_walk = self_loop[start_town];

        for (auto [cost, town] : adj[start_town])
        {
            if (cost < dist[town])
            {
                dist[town] = cost;
                pq.emplace(cost, town);
            }
        }

        while (!pq.empty())
        {
            auto [cost, town] = pq.top();
            pq.pop();

            if (cost > dist[town]) continue;

            for (auto [time, new_town] : adj[town])
            {
                ll new_cost = cost + static_cast<ll>(time);

                if (new_town == start_town)
                {
                    current_min_walk = min(current_min_walk, new_cost);
                }

                if (new_cost < dist[new_town])
                {
                    dist[new_town] = new_cost;
                    pq.emplace(new_cost, new_town);
                }
            }
        }

        min_walk[start_town] = current_min_walk == INF ? -1 : current_min_walk;
    }

    for (int i = 1; i <= N; ++i)
    {
        cout << min_walk[i] << "\n";
    }
}
