#include <bits/stdc++.h>


using namespace std;

#define ll long long
const ll MOD = 998244353;


int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector dp(N + 1, vector(K + 1, 0LL));

    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 1; k <= M; k++) {
                if (j + k <= K) dp[i + 1][j + k] += dp[i][j];
            }
        }
    }
    ll res = 0;
    for (int i = 1; i <= K; i++) {
        res = (res + dp[N][i]) % MOD;
    }
    cout << res << endl;
}