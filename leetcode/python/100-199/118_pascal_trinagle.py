from typing import List


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:

        response = []

        for row in range(numRows):
            element = []
            for key in range(row + 1):
                if key == 0 or key == row:
                    element.append(1)
                else:
                    element.append(response[row-1][key] + response[row-1][key-1])
            response.append(element)

        return response


solution = Solution()
print(solution.generate(numRows = 5))