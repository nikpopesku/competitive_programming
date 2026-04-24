#include <iostream>
#include <vector>

using namespace std;

constexpr int MOD = 1e9 + 7;

#define ll long long

class Solution {
public:
    int rearrangeSticks(const int n, const int k) {
        vector dp(n + 1, vector(k + 1, 0LL));
        for (ll i = 0; i <= min(n, k); ++i) {
            dp[i][i] = 1;
        }

        for (ll i = 1; i <= n; ++i) {
            for (ll j = 1; j <= min(i, static_cast<ll>(k)); ++j) {
                dp[i][j] = (dp[i - 1][j - 1] + (i - 1) * dp[i - 1][j] % MOD) % MOD;
            }
        }

        return static_cast<int>(dp.back().back());
    }
};

int main() {
    auto s = Solution();

    cout << s.rearrangeSticks(3, 2) << '\n';
    cout << s.rearrangeSticks(20, 11) << '\n';
}
