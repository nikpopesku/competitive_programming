import sys
from typing import List


class Solution:
    def nextGreaterElement(self, n: int) -> int:
        number = list(str(n))

        if ''.join(sorted(number, reverse=True)) == str(n):
            return -1

        x = max(i for i in range(len(number) - 1) if number[i] < number[i+1])
        y = max(i for i in range(x+1, len(number)) if number[i] > number[x])

        number[x], number[y] = number[y], number[x]

        number[x+1:len(number)] = sorted(number[x+1:len(number)])

        return int(''.join(number)) if int(''.join(number)) < 2**31 else -1



solution = Solution()
print(solution.nextGreaterElement(n = 2147483476))