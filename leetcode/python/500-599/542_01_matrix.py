import sys
from typing import List


class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        rows = len(mat)
        cols = len(mat[0])
        distance = 0
        visited = {}

        for i in range(rows):
            for j in range(cols):
                if mat[i][j] == 0:
                    key = str(i) + '_' + str(j)
                    visited[key] = 0

        while len(visited) < rows * cols:
            distance += 1

            for key in list(visited):
                if visited[key] == distance - 1:
                    i, j = [int(k) for k in key.split('_')]
                    if j >= 1 and str(i) + '_' + str(j - 1) not in visited:
                        visited[str(i) + '_' + str(j - 1)] = distance
                        mat[i][j - 1] = distance
                    if i >= 1 and str(i - 1) + '_' + str(j) not in visited:
                        visited[str(i - 1) + '_' + str(j)] = distance
                        mat[i - 1][j] = distance
                    if i + 1 <= rows - 1 and str(i + 1) + '_' + str(j) not in visited:
                        mat[i + 1][j] = distance
                        visited[str(i + 1) + '_' + str(j)] = distance
                    if j + 1 <= cols - 1 and str(i) + '_' + str(j + 1) not in visited:
                        visited[str(i) + '_' + str(j + 1)] = distance
                        mat[i][j + 1] = distance
        return mat


solution = Solution()
print(solution.updateMatrix(mat = [[0,0,0],[0,1,0],[1,1,1]]))