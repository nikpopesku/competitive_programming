from typing import List
from collections import defaultdict, Counter


class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        inDegree = defaultdict(int)
        adj = defaultdict(list)

        for e in edges:
            if e[0] == e[1]:
                return -1
            inDegree[e[1]] += 1
            adj[e[0]].append(e[1])

        stack = [(i, str(colors[i])) for i in range(len(colors)) if inDegree[i] == 0]

        if not stack:
            return -1

        maxColors = 0
        visited = len(stack)

        while stack:
            newStack = []
            for elem, path in stack:
                maxColors = max(maxColors, Counter(path).most_common(1)[0][1])

                for nei in adj[elem]:
                    inDegree[nei] -= 1

                    if inDegree[nei] == 0:
                        newStack.append((nei, path + str(colors[nei])))
                        visited += 1

            stack = newStack

        return maxColors if visited == len(colors) else -1



solution = Solution()
print(solution.largestPathValue(colors = "nnllnzznn", edges = [[0,1],[1,2],[2,3],[2,4],[3,5],[4,6],[3,6],[5,6],[6,7],[7,8]]))