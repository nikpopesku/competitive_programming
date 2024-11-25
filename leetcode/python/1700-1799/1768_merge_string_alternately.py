from typing import List
from functools import reduce


class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        return ''.join([word1[i] + word2[i] for i in range(min(len(word1), len(word2)))]) + (word1[min(len(word1), len(word2)):] if len(word1) > len(word2) else word2[min(len(word1), len(word2)):])



solution = Solution()
print(solution.mergeAlternately(word1 = "a   b   c   d", word2 = "  p   q"))