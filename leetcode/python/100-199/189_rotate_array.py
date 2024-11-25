import sys
from typing import List

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        length = len(nums)
        k = k % length

        if length <= 1 or k == 0:
            return None

        copy_nums = nums[length - k:] + nums[:-k]

        for index in range(length):
            nums[index] = copy_nums[index]

solution = Solution()
print(solution.rotate([int(x) for x in sys.argv[1:-1]], int(sys.argv[-1])))