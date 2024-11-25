from typing import List
from functools import reduce


class Solution:
    def toLowerCase(self, s: str) -> str:
        return ''.join([chr(ord(s[i]) + (32 if 65 <= ord(s[i]) <= 90 else 0)) for i in range(len(s))])



solution = Solution()
print(solution.toLowerCase(s = "Hello"))