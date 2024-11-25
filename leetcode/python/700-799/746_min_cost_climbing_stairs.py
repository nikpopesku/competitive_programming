import sys
from typing import List, Set


class Solution:
    def __init__(self):
        self.hashmap = {0: 0, 1: 0}

    def minCostClimbingStairs(self, cost: List[int]) -> int:
        for i in range(2, len(cost)+1):
            self.hashmap[i] = min(cost[i-1] + self.hashmap[i-1], cost[i-2] + self.hashmap[i-2])

        return self.hashmap[len(cost)]


solution = Solution()
print(solution.minCostClimbingStairs(cost = [1,100,1,1,1,100,1,1,100,1]))
xx = 5