import sys
from typing import List


class Solution:
    def firstUniqChar(self, s: str) -> int:
        hash = {}
        order_number = -1
        for char in s:
            order_number += 1
            hash[char] = -1 if char in hash else order_number

        minimum = None
        for key in hash:
            if hash[key] > -1 and ((minimum is not None and hash[key] < minimum) or minimum is None):
                minimum = hash[key]

        return -1 if minimum is None else minimum


solution = Solution()
print(solution.firstUniqChar(s = "leetcode"))