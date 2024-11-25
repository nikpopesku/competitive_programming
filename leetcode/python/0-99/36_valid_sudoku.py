import sys
from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:

        for i in range(9):
            one_array = [board[i][j] for j in range(9) if board[i][j] != '.']
            if len(set(one_array)) != len(one_array):
                return False

        for j in range(9):
            one_array = [board[i][j] for i in range(9) if board[i][j] != '.']
            if len(set(one_array)) != len(one_array):
                return False

        for box_number_row in range(3):
            for box_number_column in range(3):
                one_array = [board[box_number_row * 3 + i][box_number_column * 3 + j] for i in range(3) for j in range(3) if board[box_number_row * 3 + i][box_number_column * 3 + j] != '.']
                if len(set(one_array)) != len(one_array):
                    return False

        return True





solution = Solution()
print(solution.isValidSudoku(board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]))