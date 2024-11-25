from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        i, j = 0, 0
        while i < m+n and j < n:
            if nums2[j] < nums1[i]:
                del nums1[-1]
                nums1.insert(i, nums2[j])
                j += 1
                i += 1
            else:
                i += 1

        while j < n:
            nums1[m+j] = nums2[j]
            j += 1


solution = Solution()
nums1 = [4,0,0,0,0,0]
solution.merge(nums1 = nums1, m = 1, nums2 = [1,2,3,5,6], n = 5)
print(nums1)