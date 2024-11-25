import sys
from typing import List

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        l,k = 0, len(matrix)

        while l < k:
            for i in range(l, k - 1):
                matrix[i][k - 1], temp = matrix[l][i], matrix[i][k - 1]
                matrix[k - 1][k - i - 1], temp = temp, matrix[k - 1][k - i - 1]
                matrix[k - i - 1][l], temp = temp, matrix[k - i - 1][l]
                matrix[l][i] = temp

            l = l + 1
            k = k - 1



solution = Solution()
print(solution.rotate(matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]))