#include<bits/stdc++.h>

using namespace std;

#define ll long long

constexpr ll MD = 1e9 + 7;

ll pow(ll a, ll b) {
    ll response = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            response *= a % MD;
            --b;
        } else {
            a = a * a % MD;
            b >>= 1;
        }
    }

    return response;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector occ(26, 0);
    vector<ll> fact(1e6 + 1, 1);

    for (ll i = 1; i < fact.size(); ++i) {
        fact[i] = fact[i - 1] * i % MD;
    }

    string s;
    cin >> s;
    for (const char i: s) {
        ++occ[i - 'a'];
    }

    ll response = fact[s.size()];

    for (const ll i : occ) {
        if (i > 1) {
            response *= pow(fact[i], MD - 2) % MD;
        }
    }

    cout << response << '\n';
}
