from typing import List


class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        currentColor = image[sr][sc]
        key = str(sr) + '_' + str(sc)
        stack = [key]
        hash = {key: True}
        rows = len(image)
        cols = len(image[0])

        while len(stack) != 0:
            element = stack.pop(0)
            i, j = [int(k) for k in element.split('_')]
            image[i][j] = newColor

            if j >= 1 and str(i) + '_' + str(j - 1) not in hash and image[i][j-1] == currentColor:
                stack.append(str(i) + '_' + str(j - 1))
                hash[str(i) + '_' + str(j - 1)] = True
            if i >= 1 and str(i - 1) + '_' + str(j) not in hash and image[i-1][j] == currentColor:
                stack.append(str(i - 1) + '_' + str(j))
                hash[str(i - 1) + '_' + str(j)] = True
            if i + 1 <= rows - 1 and str(i + 1) + '_' + str(j) not in hash and image[i+1][j] == currentColor:
                stack.append(str(i + 1) + '_' + str(j))
                hash[str(i + 1) + '_' + str(j)] = True
            if j + 1 <= cols - 1 and str(i) + '_' + str(j + 1) not in hash and image[i][j+1] == currentColor:
                stack.append(str(i) + '_' + str(j + 1))
                hash[str(i) + '_' + str(j + 1)] = True

        return image






solution = Solution()
print(solution.floodFill([[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2))
print('xxxx')