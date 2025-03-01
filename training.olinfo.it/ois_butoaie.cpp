#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll N, K, Q, P;
    ll value;
    priority_queue<ll> pq;

    cin >> N >> K;
    cin >> P >> Q;
    for (ll i = 0; i < N; i++) {
        cin >> value;
        pq.push(value);
    }

    ll response = 0;
    vector<pair<ll, ll>> power;
    power.emplace_back(K, P);
    power.emplace_back(N - K, Q);
    if (Q > P) swap(power[0], power[1]);


    while (!pq.empty()) {
        vector<ll> parsed{};
        ll min_value = 1'000'000'000;

        for (auto &power_elem: power) {
            ll count = 0;
            while (count < power_elem.first and !pq.empty()) {
                value = pq.top();
                pq.pop();
                value = max(0LL, value - power_elem.second);
                if (value > 0) parsed.push_back(value);
                min_value = min(min_value, value / power_elem.second);
                ++count;
            }
        }
        ++response;

        if (min_value > 0) {
            response += min_value;
        }

        for (auto i = 0; i < parsed.size(); ++i) {
            ll pp = i < power[0].first ? power[0].second : power[1].second;
            pq.push(parsed[i] - min_value * pp);
        }
    }

    cout << response << "\n";
}