from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        local_max, local_min, best_profit = prices[0], prices[0], 0

        for key, value in enumerate(prices[1:]):
            if local_max < value:
                local_max = value

            if local_min > value:
                local_min = value
                local_max = value

            if local_max - local_min > best_profit:
                best_profit = local_max - local_min

        return best_profit


solution = Solution()
print(solution.maxProfit(prices = [7,1,5,3,6,4]))