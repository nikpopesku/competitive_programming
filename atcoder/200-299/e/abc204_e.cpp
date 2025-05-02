#include <cmath>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <tuple> // Needed for tuple
#include <algorithm> // Needed for max

using namespace std;

#define ll long long

// Use a large enough value, but avoid overflow when adding C
// max C is 10^9, max D is 10^18. Times can reach ~10^14 + 10^9.
// numeric_limits<ll>::max() is ~9e18. Dividing by 2 is safe.
const ll INF = numeric_limits<ll>::max() / 3; // Use 3 just to be safer

// Function to find the integer k >= 0 that minimizes k + floor(D / (k + 1))
ll find_t_best(ll D)
{
    if (D == 0) return 0;
    // Approximate minimum occurs near sqrt(D) - 1
    ll k0 = static_cast<ll>(sqrt((long double)D));
    // We only need to check k >= 0
    ll best_k = max(0LL, k0 - 2); // Start checking slightly earlier just in case
    ll min_f_k = -1; // Sentinel for first value


    // Check a small range around k0. k + D/(k+1) is convex-like.
    // Checking k0-2, k0-1, k0, k0+1, k0+2 should be sufficient.
    for (ll k_try = max(0LL, k0 - 2); k_try <= k0 + 2; ++k_try)
    {
        ll current_f_k = k_try + D / (k_try + 1); // Integer division == floor
        if (min_f_k == -1 || current_f_k < min_f_k)
        {
            min_f_k = current_f_k;
            best_k = k_try;
        }
    }
    return best_k;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout.tie(nullptr); // Not strictly necessary

    int N;
    int M; // Use int for N, M as per constraints (<= 2*10^5)
    cin >> N >> M;

    // Adjacency list: stores pairs of {neighbor, {C, D}}
    // Use long long for C and D as per constraints
    vector<vector<pair<int, pair<ll, ll>>>> adj(N + 1);

    for (int i = 0; i < M; ++i) // Loop M times for M edges
    {
        int u, v;
        ll C, D;
        cin >> u >> v >> C >> D;
        adj[u].push_back({v, {C, D}});
        adj[v].push_back({u, {C, D}}); // Undirected graph
    }

    // Dijkstra setup
    // Pair: {current_earliest_arrival_time, city_index}
    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<>> pq; // Min-heap

    // time[i] stores the earliest known arrival time at city i
    vector<ll> time(N + 1, INF);

    // Start at city 1 at time 0
    time[1] = 0;
    pq.emplace(0, 1);

    while (!pq.empty())
    {
        auto [current_time_at_city, city] = pq.top();
        pq.pop();

        // If we found a shorter path already, skip
        if (current_time_at_city > time[city])
        {
            continue;
        }

        // If we reached the destination, we can potentially optimize
        // but standard Dijkstra explores exhaustively, so let it run.
        // if (city == N) break; // This optimization is valid for non-negative weights

        // Explore neighbors
        for (auto& [fst, snd] : adj[city])
        {
            int neighbor = fst;
            const ll C = snd.first;
            const ll D = snd.second;

            // Find the best integer time k >= 0 to start waiting from
            // This k minimizes k + floor(D / (k + 1))
            ll t_best = find_t_best(D);

            // Calculate the actual departure time from 'city'
            const ll departure_time = max(current_time_at_city, t_best);

            // Calculate arrival time at 'neighbor'
            // Check for potential overflow before division
            const ll travel_duration = C + D / (departure_time + 1); // integer division is floor
            const ll arrival_at_neighbor = departure_time + travel_duration;


            // Relax the edge
            if (arrival_at_neighbor < time[neighbor])
            {
                time[neighbor] = arrival_at_neighbor;
                pq.emplace(arrival_at_neighbor, neighbor);
            }
        }
    }

    // Output the result
    if (const ll final_time = time[N]; final_time == INF)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << final_time << "\n";
    }
}
