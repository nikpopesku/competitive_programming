#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const ll MOD = 998244353;

    ll N, K, M;
    cin >> N >> K >> M;

    ll val = K;

    for (ll i = 1; i < N; ++i) {
        val = val * K % MOD;
    }

    ll val2 = M;

    for (ll i = 1; i < val; ++i) {
        val2 = val2 * M % MOD;
    }

    cout << val2 << '\n';
}