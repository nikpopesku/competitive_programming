from typing import List
from functools import reduce

def solveRow(row, k):
    '''
    O(n)
    Where n is the number of elements in the row
    '''
    n = len(row)
    k = min(k, n)
    newRow = []
    right = k
    left = 0
    total = sum(row[0: right + 1])
    newRow.append(total)

    for index in range(1, n):
        if index > k:
            total -= row[left]
            left += 1

        if index < n - k:
            right += 1
            total += row[right]
        newRow.append(total)

    return newRow

class Solution:
    def matrixBlockSum(self, mat: List[List[int]], k: int) -> List[List[int]]:
        ans = [solveRow(row,k) for row in mat]   # O(n*m)
        ans = [solveRow(x, k) for x in zip(*ans)] # O(n*m)  Transpose
        return [list(x) for x in zip(*ans)] # Transpose again

solution = Solution()
print(solution.matrixBlockSum(mat = [[67,64,78],[99,98,38],[82,46,46],[6,52,55],[55,99,45]], k = 3))