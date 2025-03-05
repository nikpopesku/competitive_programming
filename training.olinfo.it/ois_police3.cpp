#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> T(N);
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }

    // dp[i][0]: stop at i-th traffic light
    // dp[i][1]: skip i-th traffic light
    vector<vector<int>> dp(N, vector<int>(2));

    // Base case
    dp[0][0] = T[0]; // Stop at the first traffic light
    dp[0][1] = 0;    // Skip the first traffic light

    // Fill the DP table
    for (int i = 1; i < N; ++i) {
        // If we stop at the i-th traffic light, we could have stopped or skipped the previous one
        dp[i][0] = T[i] + min(dp[i-1][0], dp[i-1][1]);

        // If we skip the i-th traffic light, we must have stopped at the previous one
        dp[i][1] = dp[i-1][0];
    }

    // The answer is the minimum of stopping or skipping the last traffic light
    int result = min(dp[N-1][0], dp[N-1][1]);

    cout << result << endl;

    return 0;
}