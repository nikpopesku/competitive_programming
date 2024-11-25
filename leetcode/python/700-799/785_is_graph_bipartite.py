from typing import List
from collections import defaultdict


class Solution:
    def __init__(self):
        self.root = []
        self.rank = []

    def isBipartite(self, graph: List[List[int]]) -> bool:
        self.root = [i for i in range(len(graph))]
        self.rank = [1 for i in range(len(graph))]

        adj = defaultdict(list)

        for k, values in enumerate(graph):
            for v in values:
                adj[k].append(v)
                adj[v].append(k)

        for b, values in enumerate(graph):
            rootB = self.find(b)
            for v in values:
                rootV = self.find(v)
                if rootV == rootB:
                    return False

                for a in adj[v]:
                    rootA = self.find(a)
                    if rootA != rootB:
                        self.union(rootA, rootB)

        return len(set(self.find(a) for a in self.root if graph[a])) % 2 == 0

    def union(self, rootA: int, rootB: int):
        if self.rank[rootA] > self.rank[rootB]:
            self.root[rootB] = rootA
        elif self.rank[rootB] > self.rank[rootA]:
            self.root[rootA] = rootB
        else:
            self.root[rootA] = rootB
            self.rank[rootB] += 1

    def find(self, a: int):
        while self.root[self.root[a]] != self.root[a]:
            self.root[a] = self.root[self.root[a]]

        return self.root[a]


solution = Solution()
print(solution.isBipartite(graph=[[1],[0],[4],[4],[2,3]]))