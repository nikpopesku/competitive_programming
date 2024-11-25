from typing import List

class Solution:
    def getFactors(self, n: int):
        if n == 1:
            return []

        results = []

        def calc(target: int, start: int, combination: List[int]):
            while start * start <= target:
                if target % start == 0:
                    results.append(combination + [start, target // start])
                    calc(target // start, start, combination + [start])
                start += 1

        calc(n, 2, [])

        return results


solution = Solution()
print(solution.getFactors(n = 12))