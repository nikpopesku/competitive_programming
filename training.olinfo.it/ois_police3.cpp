#include<bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> T(N);
    for (int i = 0; i < N; i++)
        cin >> T[i];

    if (N == 1) {
        cout << "0\n";
        return 0;
    }

    if (N == 2) {
        cout <<  min(T[0], T[1]) << "\n";
        return 0;
    }

    vector<int> dp(N);
    dp[0] = T[0];
    dp[1] = min(T[1], T[0]);

    for (int i = 2; i < dp.size(); ++i) {
        dp[i] = min(dp[i-2] + T[i], dp[i-1] + T[i-1]);
    }

    cout << min(dp[N - 1], dp[N-2]) << "\n";
}