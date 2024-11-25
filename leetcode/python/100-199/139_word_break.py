from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        response = False

        for word in wordDict:
            if s[:len(word)] == word:
                n = len(s) // len(word)
                while n >= 1:
                    if len(word) * n == len(s) | response:
                        return True
                    response = response | self.wordBreak(s[len(word) * n:], wordDict)
                    if response:
                        return True
                    n -= 1

        return response


solution = Solution()
print(solution.wordBreak(s = "catskicatcats", wordDict = ["cats","cat","dog","ski"]))