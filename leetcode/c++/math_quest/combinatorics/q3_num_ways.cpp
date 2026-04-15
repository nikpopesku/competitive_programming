#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rearrangeSticks(int n, int k) {
        vector<vector<int> > dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 0; i <= min(n, k); ++i) {
            dp[i][i] = 1;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(i, k); ++j) {
                dp[i][j] = dp[i-1][j-1] + (i - 1) * dp[i-1][j];
            }
        }

        return dp.back().back();
    }
};

int main() {
    auto s = Solution();

    cout << s.rearrangeSticks(3, 2) << '\n';
}
