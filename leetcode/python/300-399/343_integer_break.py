import sys
from typing import List


class Solution:
    def integerBreak(self, n: int) -> int:
        dp = [1 for i in range(n + 1)]

        for i in range(2, n + 1):
            middle = round(i / 2)
            dp[i] = max(max(dp[j], j) * (i - j) for j in range(middle, i))

        return dp[-1]


solution = Solution()
print(solution.integerBreak(n = 10))