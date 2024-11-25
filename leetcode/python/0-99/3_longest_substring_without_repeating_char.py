import sys


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        absolute_max = 1 if len(s) >= 1 else 0
        for index_start, char_start in enumerate(s):
            unique = []
            unique.append(char_start)
            for index in range(index_start+1, len(s)):
                if s[index] in unique:
                    break
                else:
                    unique.append(s[index])
            if len(unique) > absolute_max:
                absolute_max = len(unique)

        return absolute_max


solution = Solution()
print(solution.lengthOfLongestSubstring(sys.argv[1]))