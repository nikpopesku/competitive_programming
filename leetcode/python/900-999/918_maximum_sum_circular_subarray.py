import sys
from typing import List


class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        if all(num <= 0 for num in nums):
            return max(nums)

        overall_max, overall_min = float('-inf'), float('inf')
        max_sum = 0
        min_sum = 0

        for num in nums:
            max_sum = max(max_sum, 0) + num
            min_sum = min(min_sum, 0) + num

            overall_max = max(overall_max, max_sum)
            overall_min = min(overall_min, min_sum)

        return max(overall_max, sum(nums) - overall_min)


solution = Solution()
print(solution.maxSubarraySumCircular(nums = [-3,-2,-3]))