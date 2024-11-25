from typing import List
from functools import reduce

class Solution:
    def __init__(self):
        self.hashmap = {0: 0, 1: 1, 2: 1}

    def tribonacci(self, n: int) -> int:
        for i in range(3, n + 1):
            self.hashmap[i] = self.hashmap[i - 1] + self.hashmap[i - 2] + self.hashmap[i - 3]

        return self.hashmap[n]

solution = Solution()
print(solution.tribonacci(n = 0))