import sys
from typing import List, Set

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        nodes = [[None for i in triangle[-1]] for j in range(0, len(triangle))]
        length = len(triangle)

        nodes[0][0] = triangle[0][0]

        for i in range(1, length):
            for j in range(len(triangle[i-1])+1):
                nodes[i][j] = (nodes[i-1][j-1] if j >= len(triangle[i-1]) or (j - 1 >= 0 and nodes[i-1][j-1] < nodes[i-1][j]) else nodes[i-1][j]) + triangle[i][j]

        return min(nodes[-1])




solution = Solution()
print(solution.minimumTotal(triangle = [[-1],[2,3],[1,-1,-3]]))