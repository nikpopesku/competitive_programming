from typing import List
from collections import defaultdict


class Solution:
    def __init__(self):
        self.root = []
        self.rank = []

    def minCostToSupplyWater(self, n: int, wells: List[int], pipes: List[List[int]]) -> int:
        pipes.sort(key=lambda x: x[-1])
        totalCost = 0
        self.root = [i for i in range(n)]
        self.rank = [1 for i in range(n)]

        for a, b, c in pipes:
            if self.find(a - 1) == self.find(b - 1):
                continue

            totalCost += c
            self.union(a - 1, b - 1)

        for nw in set(self.root):
            minCost = []
            for k in range(len(self.root)):
                 if self.root[k] == nw:
                    minCost.append(wells[k])
            totalCost += min(minCost)

        return totalCost

    def union(self, a: int, b: int):
        rootA, rootB = self.find(a), self.find(b)

        if rootA != rootB:
            if self.rank[rootA] > self.rank[rootB]:
                self.root[rootB] = rootA
            elif self.rank[rootA] < self.rank[rootB]:
                self.root[rootA] = rootB
            else:
                self.root[rootA] = rootB
                self.rank[rootB] += 1

    def find(self, a: int):
        if a == self.root[a]:
            return a

        self.root[a] = self.find(self.root[a])

        return self.root[a]

solution = Solution()
print(solution.minCostToSupplyWater(n = 5, wells = [46012,72474,64965,751,33304], pipes = [[2,1,6719],[3,2,75312],[5,3,44918]]))