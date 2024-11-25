from typing import Optional, List
from treenode import TreeNode

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        flag = True

        def height(root: Optional[TreeNode]) -> int:
            nonlocal flag
            if root is None:
                return 0
            heightLeft = height(root.left)
            heightRight = height(root.right)
            if abs(heightLeft - heightRight) > 1:
                flag = False

            return 1 + max(heightLeft, heightRight)

        height(root)
        return flag


r1 = TreeNode(1, TreeNode(2, TreeNode(3, TreeNode(4))), TreeNode(2, None, TreeNode(3, None, TreeNode(4))))
solution = Solution()
print(solution.isBalanced(root = r1))