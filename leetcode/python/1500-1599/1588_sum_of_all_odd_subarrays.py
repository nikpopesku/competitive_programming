from typing import List


class Solution:
    visited = {}

    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        possible_combinations = [i for i in range(1, len(arr)+1) if i % 2 == 1]

        return sum([sum(arr[i:i+length]) for length in possible_combinations for i in range(len(arr) - length + 1)])

solution = Solution()
print(solution.sumOddLengthSubarrays(arr = [1,4,2,5,3]))
xxx = 6