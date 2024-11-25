from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_current = 0
        max_so_far = None
        for num in nums:
            max_current += num
            if max_so_far is None or max_so_far < max_current:
                max_so_far = max_current

            if max_current < 0:
                max_current = 0


        return max_so_far


solution = Solution()
print(solution.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))