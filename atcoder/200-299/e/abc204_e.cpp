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
    ll min_expression = INF;

    for (ll index = max(0LL, best - 2); index <= best + 2; ++index)
    {
        if (const ll expression = index + D / (index + 1); response == -1 || expression < min_expression)
        {
            response = index;
            min_expression = expression;
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
    int A, B;
    ll C, D;
    vector<vector<pair<int, pair<ll, ll>>>> adj(N + 1);

    for (int i = 0; i < M; ++i)
    {
        cin >> A >> B >> C >> D;
        adj[A].push_back({B, {C, D}});
        adj[B].push_back({A, {C, D}});
    }

    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<>> pq;
    pq.emplace(0, 1);
    vector time(N + 1, INF);
    time[1] = 0;

    while (!pq.empty())
    {
        auto& [time_at_city, city] = pq.top();
        pq.pop();

        if (time_at_city > time[city]) continue;

        for (auto& [neighbour_city, second] : adj[city])
        {
            auto& [C, D] = second;
            ll best_time = calculate_best(D);
            const ll departure_time = max(best_time, time_at_city);
            const ll travel_time = C + D / (departure_time + 1);

            if (const ll time_at_neighbour = travel_time + departure_time; time_at_neighbour < time[neighbour_city])
            {
                time[neighbour_city] = time_at_neighbour;
                pq.emplace(time_at_neighbour, neighbour_city);
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
