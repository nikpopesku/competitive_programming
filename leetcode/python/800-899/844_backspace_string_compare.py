import sys
from typing import Optional
from math import ceil

class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        stack_s = []
        stack_t = []

        for char in s:
            if char != '#':
                stack_s.append(char)
            elif char == '#' and stack_s:
                stack_s.pop()

        for char in t:
            if char != '#':
                stack_t.append(char)
            elif char == '#' and stack_t:
                stack_t.pop()

        return stack_s == stack_t

solution = Solution()
print(solution.backspaceCompare( s = "ab#c", t = "ad#c"))
