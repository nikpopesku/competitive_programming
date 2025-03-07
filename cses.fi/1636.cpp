#include<bits/stdc++.h>

using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

ll calc(ll i, ll left_value, ll &n, vector<ll> &coins) {
    if (left_value == 0) {
        return 1;
    }

    if (left_value < 0) return 0;

    ll response = 0;

    for (ll j = i; j < n; ++j) {
        if (coins[j] > left_value) break;

        response = (response + calc(j, left_value - coins[j], n, coins)) % MOD;
    }

    return response % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    ll n, x;
    cin >> n >> x;
    vector<ll> coins(n);
    for (ll i = 0; i < n; ++i) cin >> coins[i];
    sort(coins.begin(), coins.end());

    cout << calc(0, x, n, coins) << "\n";
}