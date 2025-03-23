#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> dp(n + 1);
        dp[0] = 1;
        dp[1] = 2;

        for (int i = 2; i <= n; ++i) {
            dp[i] = (4 * dp[i - 1] - dp[i - 2] + 1000000007) % 1000000007;
        }

        //bad solution
        cout << (dp[n] * 3) % 1000000007 << endl;
    }

    return 0;
}