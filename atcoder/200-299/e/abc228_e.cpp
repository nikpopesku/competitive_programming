#include<bits/stdc++.h>

using namespace std;

#define ll long long

int pow_mod(ll x, ll n, ll m) {
    if (n == 0) return 1 % m;

    ll u = pow_mod(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;

    return u;
}

int main() {
    const ll MOD = 998244353;

    ll N, K, M;
    cin >> N >> K >> M;
    if (M % MOD == 0) {
        cout << 0 << endl;
        return 0;
    }
    ll x = pow_mod(K, N, MOD - 1);
    cout << pow_mod(M, x, MOD) << endl;
}