#include<bits/stdc++.h>

using namespace std;

// constraints
#define MAXN 200000
#define ll long long

// input data
int N, K, Q, P, i;
int V[MAXN];
ll value;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    priority_queue<ll> pq;

    assert(2 == scanf("%d%d", &N, &K));
    assert(2 == scanf("%d%d", &P, &Q));
    for (i = 0; i < N; i++) {
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