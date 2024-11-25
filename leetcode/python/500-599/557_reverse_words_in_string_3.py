import sys


def isBadVersion(version: int) -> bool:
    return version >= 1

class Solution:
    def reverseWords(self, s: str) -> str:
        string_list = s.split(' ')
        for index, element in enumerate(string_list):
            index1 = 0
            index2 = len(element) - 1
            element = list(element)
            while index1 < index2:
                element[index1], element[index2] = element[index2], element[index1]
                index1 += 1
                index2 -= 1
            string_list[index] = ''.join(element)

        return ' '.join(string_list)

solution = Solution()
print(solution.reverseWords(sys.argv[1]))