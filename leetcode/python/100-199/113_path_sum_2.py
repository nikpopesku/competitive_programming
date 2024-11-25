from typing import Optional, List
from treenode import TreeNode
import copy

class Solution:
    response = []

    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        if not root:
            return []

        stack = [(root, [])]
        response = []

        while stack:
            element, path = stack.pop()

            if element.val + sum(path) == targetSum and not element.left and not element.right:
                path.append(element.val)
                response.append(path)
            if element.left:
                temp = path[:]
                temp.append(element.val)
                stack.append((element.left, temp))
            if element.right:
                temp = path[:]
                temp.append(element.val)
                stack.append((element.right, temp))

        return response

r1 = TreeNode(-2, None, TreeNode(-3))
solution = Solution()
print(solution.pathSum(root = TreeNode(5, TreeNode(4, TreeNode(11, TreeNode(7), TreeNode(2))), TreeNode(8, TreeNode(13), TreeNode(4, TreeNode(5), TreeNode(1)))), targetSum=22))