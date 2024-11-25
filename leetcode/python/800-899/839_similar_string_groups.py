from typing import List

class Solution:
    def __init__(self):
        self.root = []
        self.rank = []
        self.strs = None

    def numSimilarGroups(self, strs: List[str]) -> int:
        self.root = [i for i in range(len(strs))]
        self.rank = [1 for i in range(len(strs))]
        self.strs = strs

        for i in range(len(strs)):
            rootA = self.find(i)
            for j in range(i+1, len(strs)):
                rootB = self.find(j)
                if rootA != rootB and self.isSimilar(i, j):
                    self.union(rootA, rootB)
                    rootA = self.find(i)

        return len(set(self.find(a) for a in self.root))

    def isSimilar(self, a: int, b: int):
        counter = 0

        for i in range(len(self.strs[a])):
            if self.strs[a][i] != self.strs[b][i]:
                counter += 1

        return True if counter <= 2 else False


    def find(self, a: int):
        if a != self.root[a]:
            self.root[a] = self.find(self.root[a])

        return self.root[a]


    def union(self, rootA: int, rootB: int):
        if self.rank[rootA] > self.rank[rootB]:
            self.root[rootB] = rootA
        elif self.rank[rootA] < self.rank[rootB]:
            self.root[rootA] = rootB
        else:
            self.root[rootA] = rootB
            self.rank[rootB] += 1

solution = Solution()
print(solution.numSimilarGroups(strs=["blw","bwl","wlb"]))
