import sys
from typing import List


class Solution:
    def __init__(self):
        self.hashtable = {0: 0, 1: 1}

    def fib(self, n: int) -> int:
        number = self.fib(n - 1) + self.fib(n - 2) if n not in self.hashtable else self.hashtable[n]

        if n not in self.hashtable:
            self.hashtable[n] = number

        return number


solution = Solution()
print(solution.fib(n = 4))