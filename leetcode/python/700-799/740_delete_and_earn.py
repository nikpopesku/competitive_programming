from typing import List

class Solution:
    def deleteAndEarn(self, nums: List[int]) -> int:
        max_points = {}

        for i in range(len(nums)):
            max_points[nums[i]] = 1 if nums[i] not in max_points else max_points[nums[i]] + 1

        max_points = [(k,v) for k, v in sorted(max_points.items(), key=lambda item: item[0])]

        used, not_used = 0, 0

        for i, (num, count) in enumerate(max_points):
            if i == 0 or max_points[i - 1][0] != num - 1:  # no previous num or not num - 1
                not_used = max(used, not_used)  # choose max
                used = count * num + not_used  # add point from this num
            else:
                temp = not_used
                not_used = max(used, not_used)
                used = count * num + temp

        return max(used, not_used)

solution = Solution()
print(solution.deleteAndEarn(nums = [8,3,4,7,6,6,9,2,5,8,2,4,9,5,9,1,5,7,1,4]))