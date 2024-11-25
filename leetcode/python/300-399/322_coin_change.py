import sys
from typing import List


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0

        if amount < min(coins):
            return -1

        dp = [float('inf')] * (amount + 1)
        dp[0] = 0

        for c in coins:
            for current_amount in range(1, amount + 1):
                if current_amount >= c:
                    dp[current_amount] = min(dp[current_amount], 1 + dp[current_amount - c])

        return dp[amount] if dp[amount] != float('inf') else -1


solution = Solution()
print(solution.coinChange(coins = [1,2,5], amount = 11))