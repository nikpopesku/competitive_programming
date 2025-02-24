import sys
from typing import List, Set

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        def directed_combinations(offset, partial_combination):
            if len(partial_combination) == k:
                result.append(list(partial_combination))
                return

            # Generate remaining combinations over {offset, ..., n - 1} of size
            # num_remaining.
            num_remaining = k - len(partial_combination)
            i = offset
            while i <= n and num_remaining <= n - i + 1:
                directed_combinations(i + 1, partial_combination + [i])
                i += 1

        result = []
        directed_combinations(1, [])
        return result





solution = Solution()
print(solution.combine(n = 4, k = 2))