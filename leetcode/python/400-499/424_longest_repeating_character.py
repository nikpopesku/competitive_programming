from typing import List

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        d = {}
        window = 0

        for i, char in enumerate(s):
            d[char] = (0 if char not in d else d[char]) + 1

            if window + 1 - max(d.values()) <= k:
                window += 1
            else:
                d[s[i - window]] -= 1

        return window





solution = Solution()
print(solution.characterReplacement(s = "ABAB", k = 2))