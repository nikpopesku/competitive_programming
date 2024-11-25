from typing import List
from functools import reduce


class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        lenght = len(mat)
        return sum([mat[i][i] + mat[i][len(mat)-1-i] for i in range(len(mat))]) - (mat[len(mat) // 2][len(mat) // 2] if len(mat) % 2 == 1 else 0)

solution = Solution()
print(solution.diagonalSum(mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]))