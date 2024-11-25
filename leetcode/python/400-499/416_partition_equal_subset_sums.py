from typing import List, Dict

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if len(nums) <= 1:
            return False

        target = sum(nums)

        if target % 2 == 1:
            return False

        memo = {}
        n = len(nums)

        return Solution.dfs(target // 2, nums, n - 1, memo) | Solution.dfs(target // 2 - nums[n-1], nums, n - 1, memo)

    @staticmethod
    def dfs(target: int, nums: List[int], n: int, memo: Dict[int, bool]) -> bool:
        if target == 0:
            return True

        if n == 0 or target < 0:
            return False

        if target in memo:
            return memo[target]

        memo[target] = Solution.dfs(target - nums[n-1], nums, n - 1, memo) | Solution.dfs(target, nums, n - 1, memo)

        return memo[target]





solution = Solution()
print(solution.canPartition(nums = [28,4,26,1,36,42,10,32,27]))