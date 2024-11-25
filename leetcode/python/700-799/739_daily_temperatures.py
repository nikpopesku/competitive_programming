from typing import List


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        response = [0] * len(temperatures)
        stack = []

        for i in range(len(temperatures)):
            while stack and temperatures[i] > temperatures[stack[-1]]:
                current = stack.pop(-1)
                response[current] = i - current
            stack.append(i)

        return response

solution = Solution()
print(solution.dailyTemperatures(temperatures = [73,74,75,71,69,72,76,73]))