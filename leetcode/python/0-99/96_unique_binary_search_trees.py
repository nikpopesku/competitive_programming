import sys
from typing import List, Set

class Solution:
    def numTrees(self, n: int) -> int:
        dp = {0: 1, 1: 1}

        if n in dp:
            return dp[n]

        for i in range(2, n + 1):

            sum_elements = 0

            for j in range(0, i):
                sum_elements += dp[j] * dp[i - j - 1]

            dp[i] = sum_elements

        return dp[n]



solution = Solution()
print(solution.numTrees(n = 5))