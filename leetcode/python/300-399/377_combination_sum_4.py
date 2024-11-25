import sys
from typing import List


class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [0 for i in range(target + 1)]
        dp[0] = 1

        for i in range(1, target + 1):
            dp[i] = sum(dp[i - num] for num in nums if i - num >= 0)

        return dp[-1]


solution = Solution()
print(solution.combinationSum4(nums = [1,2,3], target = 4))