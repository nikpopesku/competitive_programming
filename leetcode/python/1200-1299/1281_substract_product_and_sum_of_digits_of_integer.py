from typing import List
from functools import reduce

class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        l = list(str(n))
        return reduce(lambda x, y: int(x) * int(y)  , l) - reduce(lambda x, y: int(x) + int(y)  , l)

solution = Solution()
print(solution.subtractProductAndSum(n = 234))