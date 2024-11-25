import sys
from typing import List

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        unique_list_s1 = {}
        for char in s1:
            unique_list_s1[char] = unique_list_s1[char] + 1 if char in unique_list_s1 else 1

        for index in range(len(s2) - len(s1) + 1):
            unique_list_s1_copy = unique_list_s1.copy()
            for char in s2[index:index + len(s1)]:
                if char not in unique_list_s1_copy:
                    break
                unique_list_s1_copy[char] -= 1

                if unique_list_s1_copy[char] < 0:
                    break
            else:
                return True

        return False



solution = Solution()
print(solution.checkInclusion(sys.argv[1], sys.argv[2]))