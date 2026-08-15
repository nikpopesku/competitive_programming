#include<bits/stdc++.h>

using namespace std;

#define ll long long

constexpr ll MD = 1e9 + 7;

ll pow(ll a, ll b) {
    ll response = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            --b;
            response = response * a % MD;
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
    ll n, m;

    cin >> n >> m;

    vector<ll> fact(2e6 + 1, 1);
    for (ll i = 1; i < fact.size(); ++i) {
        fact[i] = fact[i - 1] * i % MD;
    }

    const ll response = (fact[n + m - 1] * pow(fact[m], MD - 2) % MD) * pow(fact[n - 1], MD - 2) % MD;


    cout << response;
}
