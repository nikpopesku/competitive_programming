import sys
from typing import List


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if obstacleGrid[-1][-1] == 1:
            return 0

        obstacle = False
        for i in range(len(obstacleGrid)):
            obstacle = obstacle or obstacleGrid[i][0] == 1
            obstacleGrid[i][0] = 1 if obstacle else -1

        obstacle = False
        for i in range(len(obstacleGrid[0])):
            obstacle = obstacle or obstacleGrid[0][i] == 1
            obstacleGrid[0][i] = 1 if obstacle else -1

        for i in range(1, len(obstacleGrid)):
            for j in range(1, len(obstacleGrid[i])):
                if obstacleGrid[i][j] == 1:
                    continue
                elif obstacleGrid[i - 1][j] == 1 and obstacleGrid[i][j - 1] == 1:
                    obstacleGrid[i][j] = 1
                else:
                    obstacleGrid[i][j] = (obstacleGrid[i - 1][j] if obstacleGrid[i - 1][j] < 0 else 0) + (
                        obstacleGrid[i][j - 1] if obstacleGrid[i][j - 1] < 0 else 0)

        return abs(obstacleGrid[-1][-1]) if obstacleGrid[-1][-1] < 0 else 0


solution = Solution()
print(solution.uniquePathsWithObstacles(obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]))