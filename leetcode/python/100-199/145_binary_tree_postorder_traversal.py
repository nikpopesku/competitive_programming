from typing import Optional, List
from treenode import TreeNode

class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        response = self.postorderTraversal(root.left) if root and root.left else []
        response += self.postorderTraversal(root.right) if root and root.right else []
        response += [root.val] if root else []

        return response

r1 = TreeNode(1, None, TreeNode(2, TreeNode(3)))
solution = Solution()
print(solution.postorderTraversal(root = r1))