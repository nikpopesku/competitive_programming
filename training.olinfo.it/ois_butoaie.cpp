#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K, Q, P;
    ll value;
    priority_queue<ll> pq;

    cin >> N >> K;
    cin >> P >> Q;
    for (int i = 0; i < N; i++) {
        cin >> value;
        pq.push(value);
    }

    int response = 0;
    vector<pair<int, int>> power;
    power.emplace_back(K, P);
    power.emplace_back(N - K, Q);
    if (Q > P) swap(power[0], power[1]);


    while (!pq.empty()) {
        vector<ll> parsed{};

        for (auto &power_elem: power) {
            int count = 0;
            while (count < power_elem.first and !pq.empty()) {
                value = pq.top();
                pq.pop();
                value = max(0LL, value - power_elem.second);
                if (value > 0) parsed.push_back(value);
                ++count;
            }
        }

        for (auto &p: parsed) pq.push(p);


        ++response;
    }

    cout << response << "\n";
}