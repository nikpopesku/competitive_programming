from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        water, max_left, max_right = 0, height[0], height[len(height) - 1]
        i, j = 0, len(height) - 1

        while i <= j:
            if max_left < max_right:
                max_left = max(max_left, height[i])
                water += max_left - height[i]
                i += 1
            else:
                max_right = max(max_right, height[j])
                water += max_right - height[j]
                j -= 1

        return water


solution = Solution()
print(solution.trap(height = [0,1,0,2,1,0,1,3,2,1,2,1]))