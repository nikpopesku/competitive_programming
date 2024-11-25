from typing import List


class Solution:
    def decodeString(self, s: str) -> str:
        num_stk,  str_stk, num  = [], [''], ''
        for i in s:
            if i.isdigit():
                num += i
            elif i.isalpha():
                str_stk[-1] += i
            elif i=='[':
                num_stk.append(int(num))
                num = ''
                str_stk.append('')
            elif i==']':
                temp = str_stk.pop()
                str_stk[-1] += num_stk.pop() * temp
        return ''.join(str_stk) if s else s

solution = Solution()
print(solution.decodeString(s = "3[a]2[bc]"))