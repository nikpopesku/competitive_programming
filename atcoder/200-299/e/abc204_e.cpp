#include <cmath>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

#define ll long long

ll INF = numeric_limits<ll>::max() / 3;

ll calculate_best(const ll D)
{
    if (D == 0) return 0;

    const ll best = static_cast<ll>(sqrt(static_cast<long double>(D)));
    ll response = -1;

    for (ll index = max(0LL, best - 2); index <= best + 2; ++index)
    {
        if (const ll expression = index + D / (index + 1); response == -1 || expression < response)
        {
            response = expression;
        }
    }

    return response;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); // Not strictly necessary

    int N;
    int M; // Use int for N, M as per constraints (<= 2*10^5)
    cin >> N >> M;
    int A, B, C, D;
    vector<vector<tuple<int, int, int>>> adj(N + 1);

    for (int i = 0; i < M; ++i)
    {
        cin >> A >> B >> C >> D;
        adj[A].emplace_back(B, C, D);
        adj[B].emplace_back(A, C, D);
    }

    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<>> pq;
    pq.emplace(0, 1);
    vector<ll> time(N + 1, INF);

    while (!pq.empty())
    {
        auto& [time_at_city, city] = pq.top();
        pq.pop();

        for (auto& [neighbour_city, C, D] : adj[city])
        {
            ll best_time = calculate_best(D);
            const ll departure_time = max(best_time, time_at_city);
            const ll travel_time = C = D / (departure_time + 1);

            ll time_at_neighbour = travel_time + departure_time;

            if (time_at_neighbour < time[neighbour_city])
            {
                time[neighbour_city] = time_at_city;
                pq.emplace(time_at_city, neighbour_city);
            }
        }
    }

    if (const ll travel_time = time[N]; travel_time == INF)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << travel_time << "\n";
    }
}
