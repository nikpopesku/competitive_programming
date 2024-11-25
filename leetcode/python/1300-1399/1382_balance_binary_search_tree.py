from typing import List
from functools import reduce
from treenode import TreeNode
import bisect


class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        values = []
        stack = [root]

        while stack:
            element = stack.pop()
            bisect.insort_left(values, element.val)

            if element.left:
                stack.append(element.left)

            if element.right:
                stack.append(element.right)

        return Solution.buildTree(values)

    @staticmethod
    def buildTree(values: list) -> TreeNode:
        middle = len(values) // 2
        left = Solution.buildTree(values[:middle]) if middle > 0 else None
        right = Solution.buildTree(values[middle + 1:]) if middle < len(values) - 1 else None

        return TreeNode(values[middle], left, right)

solution = Solution()
print(solution.balanceBST(root = TreeNode(1, None, TreeNode(2, None, TreeNode(3, None, TreeNode(4))))))