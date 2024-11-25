import sys
from typing import List

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle) > len(haystack):
            return -1

        for key, char in enumerate(haystack):
            if char == needle[0] and haystack[key:key + len(needle)] == needle:
                return key

        return -1


solution = Solution()
print(solution.strStr(haystack = "sadbutsad", needle = "sad"))