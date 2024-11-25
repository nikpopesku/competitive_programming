from typing import List


class Solution:
    def countOdds(self, low: int, high: int) -> int:
        return (high - low) // 2 + (1 if low % 2 == 1 or high % 2 == 1 else 0)

solution = Solution()
print(solution.countOdds(salary = [4000,3000,1000,2000]))