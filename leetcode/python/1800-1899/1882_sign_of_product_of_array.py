from typing import List
from functools import reduce


class Solution:
    def arraySign(self, nums: List[int]) -> int:
        product = 1
        for i in range(len(nums)):
            if nums[i] == 0:
                return 0
            product *= 1 if nums[i] > 0 else -1

        return product



solution = Solution()
print(solution.nearestValidPoint(x = 3, y = 4, points = [[1,2],[3,1],[2,4],[2,3],[4,4]]))