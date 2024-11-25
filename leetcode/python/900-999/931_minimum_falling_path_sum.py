from typing import List, Dict


class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        dp = [tuple(matrix[0])]
        length = len(matrix)

        if length > 1:
            for i in range(1, length):
                dp.append(tuple(
                    matrix[i][j] + min(dp[i - 1][j - 1] if j - 1 >= 0 else dp[i - 1][j], dp[i - 1][j],
                                       dp[i - 1][j + 1] if j + 1 <= length - 1 else dp[i - 1][j]) for j in
                    range(0, length)))

        return min(dp[-1])


solution = Solution()
print(solution.minFallingPathSum(matrix = [[2,1,3],[6,5,4],[7,8,9]]))