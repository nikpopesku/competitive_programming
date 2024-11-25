from typing import Optional, List
from treenode import TreeNode

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        def invert(node: Optional[TreeNode]):
            if node is not None and (node.left or node.right):
                node.left, node.right = node.right, node.left
                if node.left:
                    invert(node.left)
                if node.right:
                    invert(node.right)

        invert(root)

        return root

r1 = TreeNode(4, TreeNode(2), TreeNode(7))
solution = Solution()
print(solution.invertTree(root = r1))