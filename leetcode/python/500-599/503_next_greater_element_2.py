import sys
from typing import List


class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        stack, response = [], [-1] * len(nums)

        for i in range(len(nums)):
            while stack and nums[stack[-1]] < nums[i]:
                response[stack.pop()] = nums[i]
            stack.append(i)

        for num in nums:
            while stack and nums[stack[-1]] < num:
                response[stack.pop()] = num

        return response


solution = Solution()
print(solution.nextGreaterElements(nums = [1,2,1]))