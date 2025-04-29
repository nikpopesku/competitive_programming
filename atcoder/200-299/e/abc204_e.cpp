#include <cmath>
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

    int N, M, A, B, C, D;

    cin >> N >> M;
    vector<vector<tuple<int, int, int>>> adj(N + 1);

    for (int i = 1; i <= M; ++i)
    {
        cin >> A >> B >> C >> D;
        adj[A].emplace_back(B, C, D);
        adj[B].emplace_back(A, C, D);
    }

    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<>> pq;
    pq.emplace(1, 1);
    vector time(N + 1, INF);
    time[1] = 1;

    while (!pq.empty())
    {
        auto [city_time, city] = pq.top();
        pq.pop();

        if (city_time > time[city]) continue;

        for (auto [new_city, C, D] : adj[city])
        {
            if (ll new_time = city_time + C + static_cast<ll>(trunc(D / (city_time + 1))); new_time < time[new_city])
            {
                time[new_city] = new_time;
                pq.emplace(new_time, new_city);
            }
        }
    }

    ll response = 0;
    for (int i = 1; i <= N; ++i) response = max(response, time[i]);

    cout << (response == INF ? -1 : response) << "\n";
}
