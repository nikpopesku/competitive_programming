#include<bits/stdc++.h>

using namespace std;

#define ll long long

constexpr ll MD = 1e9 + 7;

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
            response /= fact[i] % MD;
        }
    }

    cout << response << '\n';
}
