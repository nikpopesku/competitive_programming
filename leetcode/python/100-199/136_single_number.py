from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        response = nums[0]
        for key in range(1, len(nums)):
            response = response ^ nums[key]

        return response


solution = Solution()
print(bin(solution.singleNumber(nums = [2,2,1])))