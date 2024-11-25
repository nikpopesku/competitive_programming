import sys
from typing import List
from math import ceil

class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        increasing, decreasing = True, True

        for i in range(1, len(nums)):
            increasing = increasing and nums[i] >= nums[i - 1]
            decreasing = decreasing and nums[i] <= nums[i - 1]

            if not increasing and not decreasing:
                return False

        return True

solution = Solution()
print(solution.isMonotonic(nums = [1,2,2,3]))
