import sys
from typing import List, Set

class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        def permute_all(index, current_string: List[str]):
            if index == len_s:
                result.append(current_string.copy())

            if index < len_s:
                lower = current_string[index].lower()
                permute_all(index+1, current_string)
                if 'a' <= lower <= 'z':
                    current_string[index] = current_string[index].upper() if lower == current_string[index] else lower
                    permute_all(index+1, current_string)

        result = []
        len_s = len(s)
        permute_all(0, list(s))
        return [''.join(i) for i in result]





solution = Solution()
print(solution.letterCasePermutation(s = "a"))