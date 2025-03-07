#include<bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const ll MOD = 1e9 + 7;


    ll n, x;
    cin >> n >> x;
    vector<ll> coins(n);
    for (ll i = 0; i < n; ++i) cin >> coins[i];
    sort(coins.begin(), coins.end());
    queue<pair<ll, ll>> q;
    ll response = 0;
    q.emplace(x, 0LL);

    while (!q.empty()) {
        auto elem = q.front();
        q.pop();
        if (elem.first < 0) continue;
        if (elem.first == 0) response = (response + 1) % MOD;
        for (ll j = elem.second; j < n; ++j) {
            if (coins[j] > elem.first) break;

            q.emplace(elem.first - coins[j], j);
        }
    }

    cout << response % MOD << "\n";
}