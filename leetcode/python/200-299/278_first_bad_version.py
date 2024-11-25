import sys


def isBadVersion(version: int) -> bool:
    return version >= 1

class Solution:
    def firstBadVersion(self, n: int) -> int:
        begin = 1
        end = n
        if end == 1:
            return end if isBadVersion(end) else 0

        while begin < end:
            key = (end + begin) // 2
            if isBadVersion(key):
                end = key
            else:
                begin = key + 1
        else:
            key = begin if isBadVersion(begin) else 0

        return key

solution = Solution()
print(solution.firstBadVersion(int(sys.argv[1])))