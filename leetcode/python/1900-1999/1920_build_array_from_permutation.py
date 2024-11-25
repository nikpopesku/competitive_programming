from typing import List

class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        return list(dict((item, nums[item]) for index, item in nums).values())