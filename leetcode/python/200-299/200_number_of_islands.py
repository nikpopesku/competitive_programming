import sys
from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        number_of_islands = 0

        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    number_of_islands += 1
                    self.callBFS(grid, i, j)

        return number_of_islands

    @staticmethod
    def callBFS(grid: List[List[str]],  i: int, j: int):
        grid[i][j] = '0'

        if i > 0 and grid[i-1][j] == '1':
            Solution.callBFS(grid, i-1, j)

        if j > 0 and grid[i][j-1] == '1':
            Solution.callBFS(grid, i, j - 1)

        if i < (len(grid) - 1) and grid[i+1][j] == '1':
            Solution.callBFS(grid, i + 1, j)

        if j < (len(grid[0]) - 1) and grid[i][j + 1] == '1':
            Solution.callBFS(grid, i, j + 1)

solution = Solution()
print(solution.numIslands(grid = [
    ["1","1","1"],
    ["0","1","0"],
    ["1","1","1"]
]))