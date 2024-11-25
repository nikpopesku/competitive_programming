from typing import Optional, List
from treenode import TreeNode


class Solution:
    def numDecodings(self, s: str) -> int:
        nums = [str(i) for i in range(1, 27)]
        n = len(s)
        dp = {}

        def dfs(index):
            if index >= n:
                return 1

            if index in dp:
                return dp[index]

            decode = 0
            for i in range(index, n):
                # if string is not in nums, no need to proceed further
                if s[index:i + 1] not in nums:
                    break
                decode += dfs(i + 1)
            dp[index] = decode
            return decode

        return dfs(0)

solution = Solution()
print(solution.numDecodings(s = "226"))