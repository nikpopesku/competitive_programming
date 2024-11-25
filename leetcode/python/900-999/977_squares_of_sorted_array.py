import sys
from typing import List

class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        length = len(nums)
        start, end = 0, length - 1
        response = [0] * length
        idx = end

        while start <= end:
            if abs(nums[end]) > abs(nums[start]):
                response[idx] = nums[end] * nums[end]
                end -= 1
            else:
                response[idx] = nums[start] * nums[start]
                start += 1
            idx -= 1

        return response


solution = Solution()
print(solution.sortedSquares([int(x) for x in sys.argv[1:]]))