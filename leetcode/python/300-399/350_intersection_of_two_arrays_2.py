from typing import List


class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res = []
        for i in nums1:
            if i in nums2:
                res.append(i)
                nums2.pop(nums2.index(i))
        return res



solution = Solution()
print(solution.intersect(nums1 = [4,9,5], nums2 = [9,4,9,8,4]))