import sys
from typing import List


class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        buy, sell = float("-inf"), 0

        for price in prices:
            temp_sell = max(sell, buy + price - fee)
            buy = max(buy, sell - price)
            sell = temp_sell

        return sell


solution = Solution()
print(solution.maxProfit(prices = [1,3,2,8,4,9], fee = 2))