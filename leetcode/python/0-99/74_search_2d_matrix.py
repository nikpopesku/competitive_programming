import sys
from typing import List

class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row_length = len(matrix[0])
        bound1, bound2 = 0 * 0, len(matrix) * row_length - 1
        middle = None

        if bound2 == 0:
            return target == matrix[0][0]

        while bound1 < bound2:
            middle = (bound2 - bound1) // 2 + bound1
            element = matrix[middle // row_length][middle % row_length]
            if element == target:
                return True

            if element < target:
                middle += 1
                bound1 = middle
                continue

            if element > target:
                bound2 = middle
                continue

        return matrix[middle // row_length][middle % row_length] == target





solution = Solution()
print(solution.searchMatrix(matrix = [[1,2]], target = 2))