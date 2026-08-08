#include <iostream>

using namespace std;

#define ll long long

constexpr ll MD = 1e9 + 7;
constexpr ll LIMIT = 1e6;

ll exp(ll a, ll p) {
    ll res = 1;

    while (p > 0) {
        if (p % 2 == 1) {
            res = res * a;
            --p;
        } else {
            a = a * a;
            p >>= 1;
        }
    }

    return res;
}

int main() {
    ll n;
    ll a, b;
    ll fact[LIMIT + 1];

    fact[0] = 1;
    fact[1] = 1;

    for (ll i = 2; i <= LIMIT; ++i) {
        fact[i] = fact[i - 1] * i % MD;
    }

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a >> b;

        cout << fact[a] * (fact[exp(b, MD - 2)] * fact[exp(a - b, MD - 2)] % MD) % MD << '\n';
    }
}
