from typing import List
from functools import reduce


class Solution:
    def isHappy(self, n: int) -> bool:
        total_iteration = 0
        while n > 1 and total_iteration < 20:
            total_sum = 0
            total_iteration += 1
            while n:
                digit = n % 10
                n = n // 10
                total_sum += digit ** 2
            if total_sum == 1:
                return True
            n = total_sum

        return True if n == 1 else False

solution = Solution()
print(solution.isHappy(n = 7))