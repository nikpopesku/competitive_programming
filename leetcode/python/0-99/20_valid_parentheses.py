

class Solution:
    def isValid(self, s: str) -> bool:
        map = {')': '(', '}': '{', ']': '['}
        stack = []

        for key,char in enumerate(s):
            if char in ['(', '[', '{']:
                stack.append(char)
            else:
                if not stack or map[char] != stack.pop():
                    return False

        return not stack

solution = Solution()
print(solution.isValid(s = "()]"))