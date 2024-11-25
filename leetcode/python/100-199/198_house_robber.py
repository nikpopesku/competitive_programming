import sys
from typing import List, Set

class Solution:
    def rob(self, nums: List[int]) -> int:
        houses = {1: nums[0]}

        houses[2] = nums[1] if len(nums) > 1 and nums[1] > nums[0] else nums[0]

        for i in range(3, len(nums)+1):
            houses[i] = max(houses[i-2] + nums[i-1], houses[i-1])

        return houses[len(nums)]





solution = Solution()
print(solution.rob(nums = [2]))