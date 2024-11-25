from typing import List

class Solution:
    def sortByBits(self, arr: List[int]) -> List[int]:
        hashmap = {}

        for i in range(len(arr)):
            count_bits = 0
            element = arr[i]
            while element:
                count_bits = count_bits + (element & 1)
                element = element >> 1
            hashmap[count_bits] = hashmap[count_bits] + [arr[i]] if count_bits in hashmap.keys() else [arr[i]]

        response = []
        for key in sorted(hashmap):
            hashmap[key].sort()
            response = response + hashmap[key]

        return response

solution = Solution()
print(solution.sortByBits(arr = [10,100,1000,10000]))