from typing import List
from functools import reduce


class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                break
        else:
            return True

        for j in range(i+1, len(s1)):
            if s1[j] != s2[j]:
                break
        else:
            return False

        return s1[:i] + s1[j] + s1[i+1:j] + s1[i] + s1[j+1:] == s2

solution = Solution()
print(solution.areAlmostEqual(s1 = "bank", s2 = "kanb"))