import sys
from typing import List


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        zeros = [index for index in range(len(nums)) if nums[index] == 0]
        for index in reversed(zeros):
            nums.pop(index)

        for index in range(len(zeros)):
            nums.append(0)

        print(nums)

solution = Solution()
print(solution.moveZeroes([int(x) for x in sys.argv[1:]]))