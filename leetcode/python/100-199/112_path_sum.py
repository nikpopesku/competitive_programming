from typing import Optional, List
from treenode import TreeNode

class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root is None:
            return False

        if root.val == targetSum and root.left is None and root.right is None:
            return True
        else:
            return self.hasPathSum(root.left, targetSum - root.val) | self.hasPathSum(root.right, targetSum - root.val)

r1 = TreeNode(-2, None, TreeNode(-3))
solution = Solution()
print(solution.hasPathSum(root = r1, targetSum = -5))