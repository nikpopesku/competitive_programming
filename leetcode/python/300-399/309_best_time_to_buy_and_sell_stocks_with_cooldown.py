import sys
from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy, sell, prev_sell = float("-inf"), 0, 0

        for i, price in enumerate(prices):
            buy = max(buy, prev_sell - price)
            prev_sell = sell
            sell = max(sell, buy + price)

        return sell


solution = Solution()
print(solution.maxProfit(prices = [1,2,3,0,2]))