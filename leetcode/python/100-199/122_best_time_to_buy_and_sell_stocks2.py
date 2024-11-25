from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0
        last_value = prices[0]
        response = 0

        for i in range(len(prices)):
            if last_value < prices[i]:
                response = response + prices[i] - last_value

            last_value = prices[i]

        return response

solution = Solution()
print(solution.maxProfit(prices = [1,9,6,9,1,7,1,1,5,9,9,9]))