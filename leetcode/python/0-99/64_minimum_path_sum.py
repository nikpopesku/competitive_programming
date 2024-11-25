import sys
from typing import List


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        dp = [[None for j in range(len(grid[0]))] for i in range(len(grid))]
        dp[0][0] = grid[0][0]

        for i in range(1, len(grid)):
            dp[i][0] = dp[i - 1][0] + grid[i][0]

        for j in range(1, len(grid[0])):
            dp[0][j] = dp[0][j - 1] + grid[0][j]

        for i in range(1, len(grid)):
            for j in range(1, len(grid[i])):
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]

        return dp[-1][-1]


solution = Solution()
print(solution.minPathSum(grid = [[1,3,1],[1,5,1],[4,2,1]]))