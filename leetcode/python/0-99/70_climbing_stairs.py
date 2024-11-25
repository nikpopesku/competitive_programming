import sys
from typing import List, Set

class Solution:
    def __init__(self):
        self.values = {1: 1, 2: 2, 3: 3}
    def climbStairs(self, n: int) -> int:
        if n not in self.values:
            self.values[n] = self.climbStairs(n-1) + self.climbStairs(n-2)

        return self.values[n]



solution = Solution()
print(solution.climbStairs(n = 10))