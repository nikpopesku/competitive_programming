from typing import List
from bisect import bisect_left

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        response = [nums[0]]

        for n in nums:
            if n > response[-1]:
                response.append(n)

            response[bisect_left(response, n)] = n

        return len(response)


solution = Solution()
print(solution.lengthOfLIS(nums = [10,9,2,5,3,7,101,18]))