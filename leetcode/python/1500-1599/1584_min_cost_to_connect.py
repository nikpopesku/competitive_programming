from typing import List
from bisect import insort_left


class Solution:
    def __init__(self):
        self.root = []
        self.rank = []

    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        connections = []
        self.root = [i for i in range(len(points))]
        self.rank = [1 for i in range(len(points))]
        totalCost = 0

        for p1 in range(len(points)):
            x1, y1 = points[p1]
            for p2 in range(p1 + 1, len(points)):
                x2, y2 = points[p2]
                cost = abs(x2 - x1) + abs(y2 - y1)
                insort_left(connections, (cost, p1, p2))

        for c, p1, p2 in connections:
            if (self.find(p1) == self.find(p2)):
                continue

            self.union(p1, p2)
            totalCost += c

        return totalCost


    def union(self, a: int, b: int):
        rootA = self.find(a)
        rootB = self.find(b)

        if rootA != rootB:
            if self.rank[rootA] > self.rank[rootB]:
                self.root[rootB] = rootA
            elif self.rank[rootB] > self.rank[rootA]:
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
print(solution.minCostConnectPoints(points = [[0,0],[2,2],[3,10],[5,2],[7,0]]))