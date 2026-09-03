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
    vector<ll> d(n + 1, 1);
    d[2] = 2;

    for (ll i = 3; i <= n; ++i) {
        d[n] = (n - 1) * ((d[n - 2] + d[n - 1]) % MD) % MD;
    }

    cout << d[n] << '\n';
}
