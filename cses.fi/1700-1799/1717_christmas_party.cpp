#include<bits/stdc++.h>

using namespace std;

#define ll long long

constexpr ll MD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> d(n + 1, 0);
    d[2] = 1;

    for (ll i = 3; i <= n; ++i) {
        d[i] = (i - 1) * ((d[i - 2] + d[i - 1]) % MD) % MD;
    }

    cout << d[n] << '\n';
}
