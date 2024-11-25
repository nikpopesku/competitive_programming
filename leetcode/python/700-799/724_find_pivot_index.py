from typing import List
from listnode import ListNode


class Solution:
    def __init__(self):
        self.last = 0

    def pivotIndex(self, nums: List[int]) -> int:
        running_sum_left = self.runningSum(nums)
        running_sum_right = self.runningSum(nums[::-1])

        if len(nums) == 1 or running_sum_right[len(nums) - 2] == 0 or running_sum_left[:len(nums) - 2] == 0:
            return 0

        for key in range(1, len(nums)):
            if running_sum_left[key] == running_sum_right[len(nums) - key - 1]:
                return key

        return -1

    def sumIt(self, num: int) -> int:
        self.last += num

        return self.last

    def runningSum(self, nums: List[int]) -> List[int]:
        self.last = 0
        return [self.sumIt(num) for num in nums]


solution = Solution()
print(solution.pivotIndex(nums = [-1,-1,0,1,1,0]))