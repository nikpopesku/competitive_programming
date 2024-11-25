from typing import List
from collections import defaultdict


class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        if n == 1:
            return 0

        queue = [headID]
        max_time = 0
        times = {headID: 0}

        childs = defaultdict(list)
        for idx, parent in enumerate(manager):
            childs[parent].append(idx)

        while queue:
            element = queue.pop(0)
            for k in childs[element]:
                queue.append(k)
                times[k] = informTime[element] + times[element]

        return max(max_time, *times.values())

solution = Solution()
print(solution.numOfMinutes(n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]))