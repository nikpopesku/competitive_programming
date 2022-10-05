import sys
from typing import List

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        visited = set()
        current_island = []
        number_of_islands = 0
        len_grid = len(grid[0]) * len(grid)
        x = 0
        y = 0

        while len(visited) < len_grid:
            if str(x) + '_' + str(y) not in visited:
                visited.add(str(x) + '_' + str(y))
                if grid[x][y] == '1':
                    current_island.append(str(x) + '_' + str(y))
                    number_of_islands += 1

            while len(current_island) != 0:
                i, j = (int(k) for k in current_island.pop(0).split('_'))

                if i < len(grid) - 1 and (str(i+1) + '_' + str(j)) not in visited:
                    visited.add(str(i + 1) + '_' + str(j))
                    if grid[i + 1][j] == '1':
                        current_island.append(str(i + 1) + '_' + str(j))

                if j < len(grid[0]) - 1 and (str(i) + '_' + str(j+1)) not in visited:
                    visited.add(str(i) + '_' + str(j + 1))
                    if grid[i][j + 1] == '1':
                        current_island.append(str(i) + '_' + str(j + 1))

            if y < (len(grid[0]) - 1):
                y += 1
            elif x < len(grid) - 1:
                x += 1
                y = 0

        return number_of_islands

solution = Solution()
print(solution.numIslands(grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]))