from typing import List
from collections import defaultdict

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        map = defaultdict(list)

        if len(prerequisites) == 0:
            return range(numCourses)

        for elem in prerequisites:
            map[elem[1]].append(elem[0])

        is_possible = True
        answer = []
        color = {k:0 for k in range(numCourses)}


        def dfs(elem):
            nonlocal is_possible

            if not is_possible:
                return

            neighbours = map[elem] if elem in map else []
            color[elem] = 1
            for k in neighbours:
                if color[k] == 1:
                    is_possible = False
                elif color[k] == 0:
                    dfs(k)

            color[elem] = 2
            answer.append(elem)

        for course in range(numCourses):
            if color[course] == 0:
                dfs(course)

        return answer[::-1] if is_possible else []

solution = Solution()
print(solution.findOrder(numCourses = 1, prerequisites = []))