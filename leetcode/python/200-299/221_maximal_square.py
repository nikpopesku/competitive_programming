import sys
from typing import List, Set

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        matrix = [[int(i) for i in row] for row in matrix]

        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 1:
                    if i - 1 < 0 or j - 1 < 0:
                        continue
                    else:
                        matrix[i][j] = min(matrix[i - 1][j - 1], matrix[i - 1][j], matrix[i][j - 1]) + 1

        return max([max(row) for row in matrix]) ** 2

solution = Solution()
print(solution.maximalSquare(matrix = [["1","1"],["1","1"]]))