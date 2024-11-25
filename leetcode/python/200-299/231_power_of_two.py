import sys
from typing import List, Set

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return False if n < 0 else bin(n).count('1') == 1





solution = Solution()
print(solution.isPowerOfTwo(n = 16))