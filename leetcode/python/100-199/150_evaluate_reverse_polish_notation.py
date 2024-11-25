
from typing import Optional, List
import operator

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        operations = {"+", "-", "*", "/"}
        stack = []

        for token in tokens:
            if token not in operations:
                stack.append(token)
            else:
                operand2 = int(stack.pop())
                operand1 = int(stack.pop())
                match token:
                    case "+":
                        element = operator.add(operand1, operand2)
                    case "-":
                        element = operator.sub(operand1, operand2)
                    case "*":
                        element = operator.mul(operand1, operand2)
                    case "/":
                        element = operator.truediv(operand1, operand2)
                        element = ceil(element) if element < 0 else floor(element)

                stack.append(element)

        return stack.pop()


solution = Solution()
print(solution.evalRPN(tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]))