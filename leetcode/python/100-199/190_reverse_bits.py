import sys
from typing import List, Set

class Solution:
    def reverseBits(self, n: int) -> int:
        response = 0
        i = 31
        while i:
            i -= 1
            response = (response + (n & 1)) << 1
            n = n >> 1

        return response + (n & 1)


solution = Solution()
print(bin(solution.reverseBits(n = int('11111111111111111111111111111101', 2))))