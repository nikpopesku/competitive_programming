from typing import List
class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])

        if m * n != r * c:
            return mat

        one_row = [j for i in mat for j in i]
        response_array = []
        response_array_element = []

        for key, value in enumerate(one_row):
            response_array_element.append(value)

            if (key + 1) % c == 0:
                response_array.append(response_array_element)
                response_array_element = []


        if len(response_array_element):
            response_array.append(response_array_element)

        return response_array

solution = Solution()
print(solution.matrixReshape(mat = [[1,2,3],[4,5,6]], r = 6, c = 1))