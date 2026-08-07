#include <iostream>

using namespace std;

#define ll long long

constexpr ll MD = 1e9 + 7;
constexpr ll LIMIT = 1e6;

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

        cout << fact[a] / (fact[b] * fact[a - b] % MD) % MD << '\n';
    }
}
