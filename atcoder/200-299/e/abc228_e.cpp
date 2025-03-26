#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll modpow(ll x, ll n, ll m) {
    if (n == 0) return 1 % m;
    ll u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const ll MOD = 998244353;

    ll N, K, M;
    cin >> N >> K >> M;

    ll val = modpow(K, N, MOD);
    cout << modpow(M, val, MOD) << '\n';
}