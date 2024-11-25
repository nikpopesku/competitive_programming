from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while left < right and nums[left] > nums[right]:
            i = (right - left) // 2
            if nums[left + i] > nums[left] and i > 0:
                left = i + left
            elif i > 0:
                right = i + left
            else:
                left = right

        if left > 0 and nums[0] <= target <= nums[left - 1]:
            return Solution.binary(nums[:left], target)

        if nums[left] <= target <= nums[-1]:
            solution = Solution.binary(nums[left:], target)
            return left + solution if solution != -1 else -1

        return -1

    @staticmethod
    def binary(nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1

        while left < right:
            middle = (right - left) // 2
            if nums[middle + left] == target:
                return middle + left
            elif target > nums[middle + left]:
                left = left + middle + 1
            else:
                right = left + middle - 1

        return left if target == nums[left] else -1



solution = Solution()
print(solution.search(nums = [4,5,6,7,0,1,2], target = 2))