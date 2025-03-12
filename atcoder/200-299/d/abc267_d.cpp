#include <bits/stdc++.h>

using namespace std;
long long dp[2001][2001];

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    dp[0][0] = 0;
    dp[0][1] = -1000000000000000000ll;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (j == 0) dp[i][0] = 0;
            else if (j > i) dp[i][j] = -1000000000000000000ll;
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i - 1] * j);
        }
    }
    cout << dp[n][m] << endl;
}