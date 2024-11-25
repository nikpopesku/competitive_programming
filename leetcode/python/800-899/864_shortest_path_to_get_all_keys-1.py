from typing import List
from itertools import permutations
from collections import deque


class Solution:
    def shortestPathAllKeys(self, grid: List[str]) -> int:
        R, C = len(grid), len(grid[0])
        # location['a'] = the coordinates of 'a' on the grid, etc.
        location = {v: (r, c)
                    for r, row in enumerate(grid)
                    for c, v in enumerate(row)
                    if v not in '.#'}

        def neighbors(r, c):
            for cr, cc in ((r-1, c), (r, c-1), (r+1, c), (r, c+1)):
                if 0 <= cr < R and 0 <= cc < C:
                    yield cr, cc

        def bfs(source, target, keys = ()):
            sr, sc = location[source]
            tr, tc = location[target]
            seen = [[False] * C for _ in range(R)]
            seen[sr][sc] = True
            queue = deque([(sr, sc, 0)])
            while queue:
                r, c, d = queue.popleft()
                if r == tr and c == tc: return d
                for cr, cc in neighbors(r, c):
                    if not seen[cr][cc] and grid[cr][cc] != '#':
                        if grid[cr][cc].isupper() and grid[cr][cc].lower() not in keys:
                            continue
                        queue.append((cr,cc,d+1))
                        seen[cr][cc] = True
            return float('inf')

        ans = float('inf')
        keys = "".join(chr(ord('a') + i) for i in range(len(location) // 2))
        for cand in permutations(keys):
            # bns : the built candidate answer, consisting of the sum
            # of distances of the segments from '@' to cand[0] to cand[1] etc.
            bns = 0
            for i, target in enumerate(cand):
                source = cand[i-1] if i > 0 else '@'
                d = bfs(source, target, cand[:i])
                bns += d
                if bns >= ans: break
            else:
                ans = bns

        return ans if ans < float('inf') else -1



solution = Solution()
grid = ["###.D.B.F.","..#b......","##....#..#","....@..#..","#d.AE.##c#",".....##.f.","#........C","..a#.#....","#....#e..#","........##"]
print(solution.shortestPathAllKeys(grid))
