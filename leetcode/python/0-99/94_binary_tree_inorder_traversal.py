from typing import Optional, List
from treenode import TreeNode


class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        response = self.inorderTraversal(root.left) if root and root.left else []
        response += [root.val] if root else []
        response += self.inorderTraversal(root.right) if root and root.right else []

        return response

r1 = TreeNode(1, None, TreeNode(2, TreeNode(3)))
solution = Solution()
print(solution.inorderTraversal(root = r1))