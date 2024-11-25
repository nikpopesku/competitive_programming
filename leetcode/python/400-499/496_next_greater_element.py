from typing import List


class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        hash = {}
        for index, value in enumerate(nums2):
            hash[value] = index

        response = []

        for index, value in enumerate(nums1):
            place = hash[value]
            answer = -1

            for i in range(place+1, len(nums2)):
                if nums2[i] > value:
                    answer = nums2[i]
                    break
            response.append(answer)

        return response



solution = Solution()
print(solution.nextGreaterElement(nums1 = [2,4], nums2 = [1,2,3,4]))