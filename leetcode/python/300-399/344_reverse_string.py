import sys
from typing import List

class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        index1 = 0
        index2 = len(s)-1
        while index1 < index2:
            s[index1], s[index2] = s[index2], s[index1]
            index1 += 1
            index2 -= 1


        print(s)

solution = Solution()
print(solution.reverseString(list(sys.argv[1])))