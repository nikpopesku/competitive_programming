import sys
from typing import List, Set

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        return matrix and [*matrix.pop(0)] + self.spiralOrder([*zip(*matrix)][::-1])



solution = Solution()
print(solution.spiralOrder(matrix = [[1,2,3],[4,5,6],[7,8,9]]))