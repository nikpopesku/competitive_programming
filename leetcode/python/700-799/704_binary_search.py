import sys
from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        begin = 0
        end = len(nums) - 1
        if end == 0:
            return 0 if nums[0] == target else -1

        while begin < end:
            key = (end + begin) // 2
            if nums[key] == target:
                break
            elif nums[key] < target:
                begin = key + 1
            else:
                end = key
        else:
            key = begin if nums[begin] == target else -1

        return key


solution = Solution()
print(solution.search([int(x) for x in sys.argv[1:-1]], int(sys.argv[-1])))