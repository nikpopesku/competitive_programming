#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector dp(m, vector(n, 1));

        for (int row = 1; row < m; ++row) {
            for (int col = 1; col < n; ++col) {
                dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

int main() {
    auto s = Solution();

    cout << s.uniquePaths(3, 7) << '\n';
}
