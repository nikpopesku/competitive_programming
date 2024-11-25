from typing import List

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        sumit = sum(piles)
        kmin = sumit // h

        begin, end = kmin + (1 if sumit % h > 0 else 0), sumit

        def calit(k):
            response = 0
            for pile in piles:
                response += pile // k
                response += (1 if pile % k > 0 else 0)

            return response

        while begin < end:
            km = (begin + end) // 2

            current_value = calit(km)

            if current_value == h and calit(km-1) > h:
                return km
            elif current_value <= h:
                end = km
            else:
                begin = km + 1

        return begin


solution = Solution()
print(solution.minEatingSpeed( piles = [312884470], h = 968709470))
