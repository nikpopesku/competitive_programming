import sys
from typing import List, Set

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_index = 0
        length = len(nums)

        for k, v in enumerate(nums):
            if k > max_index:
                return False
            max_index = max(max_index, k + v)
            if max_index >= length-1:
                return True

        return False



solution = Solution()
print(solution.canJump(nums = [1,1,1,0]))