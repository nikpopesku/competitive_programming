#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

#define ll long long

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