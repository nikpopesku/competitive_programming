from typing import List
from functools import reduce


class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        hashmap = {}
        key = 0
        for i in order:
            key = key + 1
            hashmap[i] = key

        for i in range(1, len(words)):
            size = min(len(words[i-1]), len(words[i]))
            for j in range(size):
                if hashmap[words[i-1][j]] > hashmap[words[i][j]]:
                    return False
                elif hashmap[words[i-1][j]] < hashmap[words[i][j]]:
                    break
            else:
                if len(words[i-1]) > len(words[i]):
                    return False

        return True


solution = Solution()
print(solution.isAlienSorted(words = ["kuvp","q"], order = "ngxlkthsjuoqcpavbfdermiywz"))