import sys
from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for index1 in range(len(numbers)):
            try:
                index2 = numbers.index(target - numbers[index1], index1 + 1)

                return [index1 + 1, index2 + 1]
            except ValueError:
                continue

solution = Solution()
print(solution.twoSum([int(x) for x in sys.argv[1:-1]], int(sys.argv[-1])))