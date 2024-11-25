from typing import List

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        max_area = 0
        key = self.key(0, 0)
        visited = {}
        queue_water = [key] if grid[0][0] == 0 else []
        queue_island = [key] if grid[0][0] else []
        current_area = 0
        rows = len(grid)
        cols = len(grid[0])

        while len(queue_water) != 0 or len(queue_island) != 0:
            key = queue_island.pop(0) if len(queue_island) != 0 else queue_water.pop(0)
            if key in visited:
                continue
            else:
                visited[key] = True
            i, j = [int(k) for k in key.split('_')]
            current_area = current_area + 1 if grid[i][j] else 0
            max_area = max(max_area, current_area)

            if i - 1 >= 0 and self.key(i - 1, j) not in visited:
                new_key = self.key(i - 1, j)
                if grid[i-1][j]:
                    queue_island.append(new_key)
                    if grid[i][j] == 0:
                        continue
                else:
                    queue_water.append(new_key)
            if i + 1 <= rows - 1 and self.key(i + 1, j) not in visited:
                new_key = self.key(i + 1, j)
                if grid[i+1][j]:
                    queue_island.append(new_key)
                    if grid[i][j] == 0:
                        continue
                else:
                    queue_water.append(new_key)
            if j - 1 >= 0 and self.key(i, j - 1) not in visited:
                new_key = self.key(i, j - 1)
                if grid[i][j-1]:
                    queue_island.append(new_key)
                    if grid[i][j] == 0:
                        continue
                else:
                    queue_water.append(new_key)
            if j + 1 <= cols -1 and self.key(i, j + 1) not in visited:
                new_key = self.key(i, j + 1)
                if grid[i][j+1]:
                    queue_island.append(new_key)
                    if grid[i][j] == 0:
                        continue
                else:
                    queue_water.append(new_key)

            if len(queue_island) == 0:
                current_area = 0

        return max_area

    def key(self, i, j):
        return str(i) + '_' + str(j)






solution = Solution()
print(solution.maxAreaOfIsland(grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]))
print('xxxx1')
print(solution.maxAreaOfIsland(grid = [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]))
print('xxxx2')
print(solution.maxAreaOfIsland(grid = [[0,1],[1,0]]))