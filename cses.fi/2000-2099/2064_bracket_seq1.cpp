#include<bits/stdc++.h>

using namespace std;

#define ll long long

constexpr ll MD = 1e9 + 7;

ll exp(ll a, ll b) {
    ll result = 1;

    while (b > 0) {
        if (b % 2 == 1) {
            result = result * a % MD;
            --b;
        } else {
            b >>= 1;
            a = a * a % MD;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll k;
    cin >> k;
    const ll n = k / 2;

    vector<ll> fact(2 * n + 1, 1);
    for (ll i = 2; i < 2 * n + 1; ++i) fact[i] = i * fact[i - 1] % MD;

    cout << (fact[2 * n] * exp(fact[n + 1], MD - 2) % MD) * exp(fact[n], MD - 2) % MD;
}
