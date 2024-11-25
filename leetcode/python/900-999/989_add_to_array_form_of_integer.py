import sys
from typing import List

class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        return [int(c) for c in list(str(int(''.join(str(c) for c in num)) + k))]


solution = Solution()
print(solution.addToArrayForm(num = [1,2,0,0], k = 34))