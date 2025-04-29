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

    ll extreme_D = INF;
    ll ultimate_response = INF;

    for (auto [new_city, C, D] : adj[1])
    {
        extreme_D = min(extreme_D, static_cast<ll>(D));
    }

    for (int i = 0; i <= extreme_D; ++i)
    {
        priority_queue<T, vector<T>, greater<>> pq;
        vector time(N + 1, INF);

        pq.emplace(i, 1);
        time[1] = i;

        while (!pq.empty())
        {
            auto [city_time, city] = pq.top();
            pq.pop();

            if (city_time > time[city]) continue;

            for (auto& elem : adj[city])
            {
                int new_city = get<0>(elem);
                C = get<1>(elem);
                D = get<2>(elem);
                if (ll new_time = city_time + C + static_cast<ll>(trunc(D / (city_time + 1))); new_time < time[
                    new_city])
                {
                    time[new_city] = new_time;
                    pq.emplace(new_time, new_city);
                }
            }
        }

        ll response = 0;
        for (int j = 1; j <= N; ++j) response = max(response, time[j]);
        ultimate_response = min(ultimate_response, response);
    }


    cout << (ultimate_response == INF ? -1 : ultimate_response) << "\n";
}
