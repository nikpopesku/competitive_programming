from typing import List
from functools import reduce


class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        hash = {}
        for i in range(len(s)):
            hash[s[i]] = hash[s[i]] + 1 if s[i] in hash.keys() else 1
        for i in range(len(t)):
            if t[i] not in hash.keys():
                return t[i]
            elif hash[t[i]] == 0:
                return t[i]
            else:
                hash[t[i]] = hash[t[i]] - 1


solution = Solution()
print(solution.findTheDifference(s = "abcd", t = "abcde"))