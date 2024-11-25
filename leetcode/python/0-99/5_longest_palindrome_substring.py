import sys


class Solution:
    def longestPalindrome(self, s: str) -> str:
        maxp = 1
        maxsub = s[0]

        for i in range(len(s)):
            for j in range(i + maxp, len(s)):
                temp = s[i:j+1]
                if temp == temp[::-1]:
                    maxp = j + 1 - i
                    maxsub = s[i:j+1]

        return maxsub


solution = Solution()
print(solution.longestPalindrome(s = "bb"))