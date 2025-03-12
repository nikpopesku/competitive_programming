#include<iostream>

using namespace std;
int N, M;
int A[2000];
long dp[2020];

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int j = 0; j <= M; j++) dp[j] = -1e18;
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = M; j--;)dp[j + 1] = max(dp[j + 1], dp[j] + (j + 1) * (long) A[i]);
    }
    cout << dp[M] << endl;
}
