from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        count_characters = len(strs[0])
        current_set = set(string[0:count_characters] for string in strs)

        while len(current_set) > 1:
            count_characters = count_characters - 1
            current_set = set(string[0:count_characters] for string in current_set)

        return next(iter(current_set))




solution = Solution()
print(solution.longestCommonPrefix(strs = ["flower","flow","flight"]))