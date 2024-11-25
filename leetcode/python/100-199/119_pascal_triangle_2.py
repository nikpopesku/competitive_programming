from typing import Optional, List
from treenode import TreeNode

class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        if rowIndex == 0:
            return [1]

        if rowIndex == 1:
            return [1, 1]

        dp = (1, 1)

        for i in range(2, rowIndex + 1):
            dp = tuple(1 if j == 0 or j == len(dp) else dp[j - 1] + dp[j] for j in range(i + 1))

        return list(dp)


solution = Solution()
print(solution.getRow(rowIndex = 3))