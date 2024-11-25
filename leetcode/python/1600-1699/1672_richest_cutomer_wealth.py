from typing import List
from functools import reduce


class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> list:
        return max([sum(i) for i in accounts])

solution = Solution()
print(solution.maximumWealth(accounts = [[1,2,3],[3,2,1]]))