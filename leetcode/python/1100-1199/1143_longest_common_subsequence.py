from typing import List
from functools import reduce


class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        l1 = len(text1)
        l2 = len(text2)

        dp = [[0] * (l2 + 1) for _ in range(l1 + 1)]

        for row in range(1, l1 + 1):
            for col in range(1, l2 + 1):
                if text1[row - 1] == text2[col - 1]:
                    dp[row][col] = dp[row - 1][col - 1] + 1
                else:
                    dp[row][col] = max(dp[row - 1][col], dp[row][col - 1])

        return dp[l1][l2]


solution = Solution()
print(solution.longestCommonSubsequence(text1 = "oxcpqrsvwf", text2 = "shmtulqrypy" ))