import sys
from typing import List


class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        hash = {}
        for char in magazine:
            hash[char] = 1 if char not in hash else hash[char] + 1

        for char in ransomNote:
            if char not in hash or hash[char] == 0:
                return False
            else:
                hash[char] -= 1

        return True

solution = Solution()
print(solution.canConstruct(ransomNote = "aa", magazine = "aab"))