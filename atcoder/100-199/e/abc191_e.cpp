#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define ll long long


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    constexpr ll BIG = 1e18;

    int N, M, A, B, C;

    cin >> N >> M;
    vector<vector<pair<int, int>>> adj(N + 1);
    vector min_walk(N + 1, BIG);

    for (int i = 0; i < M; ++i)
    {
        cin >> A >> B >> C;

        adj[A].emplace_back(C, B);
    }

    priority_queue<pair<ll, int>> pq;

    for (int start_town = 1; start_town <= N; ++start_town)
    {
        if (min_walk[start_town] != BIG) continue;
        int count = 0;
        pq.emplace(0, start_town);

        while (!pq.empty())
        {
            const auto& [cost, town] = pq.top();
            pq.pop();
            bool there_are_neighbours = false;

            if (cost > min_walk[start_town]) continue;
            if (count > N + 1) break;

            for (auto& [time, new_town] : adj[town])
            {
                if (ll new_cost = cost + static_cast<ll>(time); new_cost < min_walk[start_town])
                {
                    pq.emplace(new_cost, new_town);
                    there_are_neighbours = true;
                }
            }

            if (there_are_neighbours) ++count;
        }
    }


    for (int i = 1; i <= N; ++i) cout << (min_walk[i] != BIG ? min_walk[i] : -1) << "\n";
}
