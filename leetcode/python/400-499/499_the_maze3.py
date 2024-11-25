from typing import List
from heapq import heappop, heappush
from collections import defaultdict


class Solution:
    def findShortestWay(self, maze: List[List[int]], ball: List[int], hole: List[int]) -> str:
        m, n = len(maze), len(maze[0])
        directions = {'d': (1, 0), 'u': (-1, 0), 'r': (0, 1), 'l': (0, -1)}
        pq = [(0, tuple(ball), '')]
        minDistance = float('inf')
        minInstruction = 'impossible'
        visited = defaultdict(lambda: float('inf'))

        while pq:
            distance, node, instruction = heappop(pq)
            x, y = node

            for instr, direction in directions.items():
                dx, dy = direction
                counter = 0
                nx, ny = x, y
                while 0 <= nx + dx < m and 0 <= ny + dy < n and maze[nx + dx][ny + dy] == 0:
                    counter += 1
                    nx, ny = dx + nx, dy + ny
                    if nx == hole[0] and ny == hole[1]:
                        if minDistance > distance + counter:
                            minDistance = distance + counter
                            minInstruction = instruction + instr
                        elif minDistance == distance + counter:
                            minInstruction = min(minInstruction, instruction + instr)

                if counter > 0 and visited[(nx, ny)] > distance + counter:
                    heappush(pq, (distance + counter, (nx, ny), instruction + instr))
                    visited[(nx, ny)] = distance + counter

        return minInstruction


solution = Solution()
print(solution.findShortestWay(maze = [[0,1,0,0,1,0,0,1,0,0],[0,0,1,0,0,1,0,0,1,0],[0,0,0,0,0,0,1,0,0,1],[0,0,0,0,0,0,1,0,0,1],[0,1,0,0,1,0,0,1,0,0],[0,0,1,0,0,1,0,0,0,0],[0,0,0,0,0,0,1,0,0,0],[1,0,0,1,0,0,0,0,0,1],[0,1,0,0,1,0,0,1,0,0],[0,0,0,0,0,1,0,0,1,0]], ball = [2,4], hole = [7,6]))