import sys


class Solution:
    def longestPalindrome(self, s: str) -> int:
        right = []
        without_pair = {}
        for key in s:
            if key not in without_pair:
                without_pair[key] = key
            else:
                right.append(key)
                del without_pair[key]


        return (1 if len(without_pair) >= 1 else 0) + 2 * len(right)




solution = Solution()
print(solution.longestPalindrome(sys.argv[1]))