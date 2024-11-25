import sys
from typing import List

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        begin = 0
        end = len(nums) - 1
        if end == 0:
            return end + 1 if target > nums[end] else end

        while begin < end:
            key = (end + begin) // 2
            if nums[key] == target:
                break
            elif nums[key] < target:
                begin = key + 1
            else:
                end = key
        else:
            key = begin + 1 if target > nums[begin] else begin

        return key

solution = Solution()
print(solution.searchInsert([int(x) for x in sys.argv[1:-1]], int(sys.argv[-1])))