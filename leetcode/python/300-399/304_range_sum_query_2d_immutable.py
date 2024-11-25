import sys
from typing import List


class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.matrix = matrix
        self.sums = {}

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        total = 0

        for row in range(row1, row2 + 1):
            if (row, col1, col2) not in self.sums:
                self.sums[(row, col1, col2)] = sum(self.matrix[row][col1:col2 + 1])

            total += self.sums[(row, col1, col2)]

        return total

obj = NumArray(nums)
param_1 = obj.sumRange(left,right)
print(solution.reverseString(list(sys.argv[1])))