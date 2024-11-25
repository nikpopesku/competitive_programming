from typing import List


class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        return s in s[1:] + s[:-1]


solution = Solution()
print(solution.repeatedSubstringPattern(s = "abab"))