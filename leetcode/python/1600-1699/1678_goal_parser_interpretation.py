from typing import List
from functools import reduce


class Solution:
    def interpret(self, command: str) -> str:
        hashmap = {'()': {'length': 2, 'value': 'o'}, '(al)': {'length': 4, 'value': 'al'}}
        lengths = [i['length'] for i in hashmap.values()]
        answer = []
        i = 0
        while i < len(command):
            for length in lengths:
                if (i + length) <= len(command) and command[i:i+length] in hashmap.keys():
                    element = hashmap[command[i:i+length]]['value']
                    break
            else:
                length = 1
                element = command[i]
            answer.append(element)
            i = i + length

        return ''.join(answer)

solution = Solution()
print(solution.interpret(command = "G()(al)"))