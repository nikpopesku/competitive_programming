from typing import List
from ntreenode import Node


class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        response = []

        if root:
            response += [root.val]

            while root.children:
                child = root.children.pop(0)
                response += self.preorder(child)

        return response


solution = Solution()
print(solution.preorder(root = [1,null,3,2,4,null,5,6]))