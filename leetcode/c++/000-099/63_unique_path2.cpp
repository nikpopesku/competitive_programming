#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;

        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector dp(n, vector(m, 0));
        dp[0][0] = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && j == 0) continue;
                dp[i][j] = (i > 0 && obstacleGrid[i - 1][j] != 1 ? dp[i - 1][j] : 0) + (
                               j > 0 && obstacleGrid[i][j - 1] != 1 ? dp[i][j - 1] : 0);
            }
        }

        return dp[n - 1][m - 1];
    }
};

int main() {
    auto s = Solution();

    vector<vector<int> > obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << s.uniquePathsWithObstacles(obstacleGrid) << '\n';
}
