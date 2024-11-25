from collections import defaultdict
from typing import List

class Solution:
    def __init__(self):
        self.root = []
        self.rank = []
        self.emails = defaultdict(list)
        self.response = defaultdict(set)

    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        self.root = [i for i in range(len(accounts))]
        self.rank = [1 for i in range(len(accounts))]

        for i in range(len(accounts)):
            for e in accounts[i][1:]:
                self.emails[e].append(i)

        for e in self.emails:
            if len(self.emails[e]) <= 1:
                continue

            for i in self.emails[e]:
                for j in self.emails[e]:
                    if i != j and accounts[i][0] == accounts[j][0] and self.find(i) != self.find(j):
                        self.union(i, j)

        for i in range(len(accounts)):
            for e in accounts[i][1:]:
                self.response[self.root[i]].add(e)

        toBeRemoved = set()
        for k, v in self.response.items():
            if k != self.find(k):
                toBeRemoved.add(k)

        while toBeRemoved:
            k = toBeRemoved.pop()
            rootK = self.find(k)
            for e in self.response[k]:
                self.response[rootK].add(e)
            del self.response[k]

        return [[accounts[k][0], *sorted(v)] for k, v in self.response.items()]

    def union(self, a: int, b: int):
        rootA = self.find(a)
        rootB = self.find(b)

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


xxx = Solution()
yyy = xxx.accountsMerge([["David","David0@m.co","David1@m.co"],["David","David3@m.co","David4@m.co"],["David","David4@m.co","David5@m.co"],["David","David2@m.co","David3@m.co"],["David","David1@m.co","David2@m.co"]])
print(yyy)