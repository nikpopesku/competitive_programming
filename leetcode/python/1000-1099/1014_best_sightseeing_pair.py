import sys
from typing import List


class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        response = 0
        maxi = 0

        for k in range(len(values)):
            response = max(response, maxi + values[k] - k)
            maxi = max(maxi, values[k] + k)

        return response


solution = Solution()
print(solution.maxScoreSightseeingPair(values = [1,2]))