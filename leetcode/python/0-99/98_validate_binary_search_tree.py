from typing import Optional, List
from treenode import TreeNode

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.dfs(root, float('-inf'), float('inf'))

    def dfs(self, node, lower, upper):
        if not node:
            return True

        if lower < node.val < upper:
            return self.dfs(node.left, lower, node.val) and self.dfs(node.right, node.val, upper)

        return False


r1 = TreeNode(5, TreeNode(4), TreeNode(8, TreeNode(7, TreeNode(6)), TreeNode(9)))
solution = Solution()
print(solution.isValidBST(root = r1))