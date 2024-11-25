import sys
from typing import List, Set

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def permute_all(i):
            if i == len(nums) - 1:
                result.append(nums.copy())

            j = i
            while j < len(nums):
                nums[i], nums[j] = nums[j], nums[i]
                permute_all(i+1)
                nums[j], nums[i] = nums[i], nums[j]
                j += 1

        result = []
        permute_all(0)
        return result





solution = Solution()
print(solution.permute(nums = [1,2,3]))