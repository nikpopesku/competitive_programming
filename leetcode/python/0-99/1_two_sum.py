from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}
        for key, num in enumerate(nums):
            remaining = target - num

            if remaining in seen:
                return [key, seen[remaining]]

            seen[num] = key


solution = Solution()
print(solution.twoSum([3, 3], target = 6))