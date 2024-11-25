import sys


class Solution:
    def romanToInt(self, s: str) -> int:
        letters = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        special_combinations = {'IV': 4, 'IX': 9, 'XL': 40, 'XC': 90, 'CD': 400, 'CM': 900}

        answer = 0
        index = 0
        length = len(s)
        while index < length:
            has_special_next = index + 1 < length and (s[index] + s[index + 1]) in special_combinations
            if s[index] in letters and not has_special_next:
                answer += letters[s[index]]
                index += 1
            elif has_special_next:
                answer += special_combinations[s[index] + s[index + 1]]
                index += 2

        return answer



solution = Solution()
print(solution.romanToInt(sys.argv[1]))