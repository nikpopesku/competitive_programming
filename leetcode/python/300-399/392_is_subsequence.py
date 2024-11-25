from typing import List


class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if len(s) == 0:
            return True

        if len(t) == 0:
            return False

        counter = 0

        for t0 in t:
            if s[counter] == t0:
                counter += 1
                if counter == len(s):
                    return True

        return False


solution = Solution()
print(solution.isSubsequence(s = "abc", t = "ahbgdc"))