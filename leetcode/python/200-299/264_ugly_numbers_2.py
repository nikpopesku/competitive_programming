import sys
from typing import List, Set

class Solution:
    def nthUglyNumber(self, n: int) -> int:
        dp = [1]
        dp_set = {1}

        index2 = 0
        index3 = 0
        index5 = 0

        if n <= len(dp):
            return dp[n-1]

        while len(dp) < n:
            number2 = dp[index2] * 2
            number3 = dp[index3] * 3
            number5 = dp[index5] * 5
            number = min(number2, number3, number5)

            if number == number2:
                index2 += 1
            elif number == number3:
                index3 += 1
            else:
                index5 += 1

            if number in dp_set:
                continue

            dp.append(number)
            dp_set.add(number)

        return dp[n-1]




solution = Solution()
print(solution.nthUglyNumber(n = 268))