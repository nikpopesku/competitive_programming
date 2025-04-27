#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

#define ll long long
constexpr ll INF = numeric_limits<ll>::max() / 2; // Use a safer large value

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A, B, C;

    cin >> N >> M;
    vector<vector<pair<int, int>>> adj(N + 1);
    vector min_walk(N + 1, -1LL);
    vector self_loop(N + 1, INF);

    for (int i = 0; i < M; ++i)
    {
        cin >> A >> B >> C;

        if (A == B)
        {
            self_loop[A] = min(self_loop[A], static_cast<ll>(C));
        }
        else
        {
            adj[A].emplace_back(C, B);
        }
    }

    using T = pair<ll, int>;

    for (int start_town = 1; start_town <= N; ++start_town)
    {
        priority_queue<T, vector<T>, greater<>> pq;
        ll current_min_walk = self_loop[start_town];
        vector dist(N + 1, INF);

        for (auto& [cost, town] : adj[start_town])
        {
            if (static_cast<long long>(cost) < dist[town])
            {
                pq.emplace(cost, town);
                dist[town] = cost;
            }
        }


        while (!pq.empty())
        {
            const auto [cost, town] = pq.top();
            pq.pop();

            if (cost > dist[town]) continue;

            for (auto& [time, new_town] : adj[town])
            {
                ll new_cost = cost + static_cast<ll>(time);

                if (new_town == start_town)
                {
                    current_min_walk = min(current_min_walk, new_cost);
                }

                if (new_cost < dist[new_town])
                {
                    pq.emplace(new_cost, new_town);
                    dist[new_town] = new_cost;
                }
            }
        }

        min_walk[start_town] = current_min_walk != INF ? current_min_walk : -1;
    }


    for (int i = 1; i <= N; ++i) cout << min_walk[i] << "\n";
}
