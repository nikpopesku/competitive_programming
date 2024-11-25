from typing import List

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        pacific_queue = []
        atlantic_queue = []
        height = len(heights)
        length = len(heights[0])

        for i in range(length):
            pacific_queue.append([0, i])
            atlantic_queue.append([height - 1, i])

        for j in range(height):
            if [j, 0] not in pacific_queue:
                pacific_queue.append([j, 0])
            if [j, length - 1] not in atlantic_queue:
                atlantic_queue.append([j, length - 1])

        list1 = Solution.bfs(pacific_queue, heights)
        list2 = Solution.bfs(atlantic_queue, heights)

        return [element for element in list1 if element in list2]

    @staticmethod
    def bfs(queue: List[List[int]], heights: List[List[int]]):
        counter = 0

        while counter < len(queue):
            row, col = queue[counter]

            for direction_row, direction_col in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
                new_row, new_col = row + direction_row, col + direction_col

                if new_row < 0 or new_row >= len(heights) or new_col < 0 or new_col >= len(heights[0]):
                    continue
                if [new_row, new_col] in queue:
                    continue
                if heights[new_row][new_col] < heights[row][col]:
                    continue

                queue.append([new_row, new_col])

            counter += 1

        return queue




solution = Solution()
print(solution.pacificAtlantic(heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]))