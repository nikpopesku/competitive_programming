from ntreenode import Node


class Solution:
    def maxDepth(self, root: Node) -> int:
        queue = [[root]]

        response = 0

        while queue:
            elements = queue.pop(0)
            response = response + 1

            temp = []
            for element in elements:
                if element.children:
                    for child in element.children:
                        temp.append(child)

            if temp:
                queue.append(temp)

        return response


solution = Solution()
print(solution.maxDepth(Node(1, [Node(3, [Node(5), Node(6)]), Node(2), Node(4)])))