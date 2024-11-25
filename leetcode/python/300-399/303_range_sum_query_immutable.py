import sys
from typing import List


class NumArray:

    def __init__(self, nums: List[int]):
        self.nums = nums

    def sumRange(self, left: int, right: int) -> int:
        return sum(self.nums[left:right + 1])

obj = NumArray(nums)
param_1 = obj.sumRange(left,right)
print(solution.reverseString(list(sys.argv[1])))