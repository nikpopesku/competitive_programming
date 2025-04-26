#include <algorithm>
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

    constexpr ll SMALL = -1e18;
    int N, M;

    cin >> N >> M;
    vector<int> spaces(N + 1);
    vector<vector<pair<int, int>>> adj(N + 1);

    for (int i = 1; i <= N; ++i)
    {
        cin >> spaces[i];
    }

    int space1, space2;
    vector happiness(N + 1, SMALL);

    for (int j = 0; j < M; ++j)
    {
        cin >> space1 >> space2;
        int cost, cost_inverse;

        if (spaces[space1] >= spaces[space2])
        {
            cost = spaces[space1] - spaces[space2];
            cost_inverse = -2 * cost;
        }
        else
        {
            cost_inverse = spaces[space2] - spaces[space1];
            cost = -2 * cost_inverse;
        }

        adj[space1].emplace_back(cost, space2);
        adj[space2].emplace_back(cost_inverse, space1);
    }

    priority_queue<pair<ll, int>> pq;
    ll max_happiness = 0;
    pq.emplace(0, 1);

    while (!pq.empty())
    {
        auto [happy, space] = pq.top();
        pq.pop();
        if (happy < happiness[space]) continue;

        happiness[space] = happy;

        for (auto& [price, new_space] : adj[space])
        {
            if (ll new_happiness = happy + static_cast<ll>(price); new_happiness > happiness[new_space])
            {
                pq.emplace(new_happiness, new_space);
                max_happiness = max(max_happiness, new_happiness);
            }
        }
    }


    cout << max_happiness << '\n';
}
