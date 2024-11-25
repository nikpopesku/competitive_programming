import sys
from typing import List


class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        dp = {}

        def calc(l, r):
            if (l, r) in dp:
                return dp[(l, r)]

            if l > r:
                return 0
            if l == r:
                return 1

            dp[(l, r)] = 2 + calc(l + 1, r - 1) if s[l] == s[r] else max(calc(l + 1, r), calc(l, r - 1))

            return dp[(l, r)]

        return calc(0, len(s) - 1)


solution = Solution()
print(solution.longestPalindromeSubseq(s = "aabaa"))