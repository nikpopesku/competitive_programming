from typing import List
from functools import reduce


class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        arr.sort()
        delta = arr[1] - arr[0]
        for i in range(2, len(arr)):
            if arr[i] - delta != arr[i-1]:
                return False

        return True


solution = Solution()
print(solution.canMakeArithmeticProgression(arr = [3,5,1]))