from typing import List
from collections import Counter

class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        words = sorted(words)

        return [i[0] for i in Counter(words).most_common(k)]





solution = Solution()
print(solution.topKFrequent(words = ["i","love","leetcode","i","love","coding"], k = 3))