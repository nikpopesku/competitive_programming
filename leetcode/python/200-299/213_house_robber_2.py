import sys
from typing import List, Set

class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        return max(self.robit(nums[1:]), self.robit(nums[:-1]))

    def robit(self, nums: List[int]) -> int:
        houses = {1: nums[0], 2: nums[1] if len(nums) > 1 and nums[1] > nums[0] else nums[0]}

        for i in range(3, len(nums) + 1):
            houses[i] = max(houses[i - 1], nums[i - 1] + houses[i - 2])

        return houses[len(nums)]





solution = Solution()
print(solution.rob(nums = [2]))