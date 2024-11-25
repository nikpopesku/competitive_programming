import sys
from typing import List, Set

class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0

        start, end = 0, 0  # indices in nums of current range
        max_index = 0
        steps = 1

        while True:  # will always terminate since last index is accessible
            for i in range(start, end + 1):
                max_index = max(max_index, i + nums[i])
            if max_index >= len(nums) - 1:
                return steps
            steps += 1
            start, end = end + 1, max_index



solution = Solution()
print(solution.jump(nums = [1,2,1,1,1]))