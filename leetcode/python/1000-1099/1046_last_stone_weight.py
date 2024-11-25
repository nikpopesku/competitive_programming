from typing import List
import heapq


class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        updated_stones = []

        if len(stones) == 1:
            return stones[0]

        for value in stones:
            heapq.heappush(updated_stones, -value)

        for i in range(len(stones) - 1):
            heapq.heappush(updated_stones, heapq.heappop(updated_stones) - heapq.heappop(updated_stones))

        return abs(updated_stones[0])


solution = Solution()
print(solution.lastStoneWeight(stones = [2,7,4,1,8,1]))