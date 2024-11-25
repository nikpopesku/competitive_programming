import sys
from typing import List, Set

class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n:
            count += n & 1
            n = n >> 1

        return n



solution = Solution()
print(solution.hammingWeight(n = 5))