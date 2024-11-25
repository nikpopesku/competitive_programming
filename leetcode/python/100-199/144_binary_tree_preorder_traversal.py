from typing import Optional, List
from treenode import TreeNode

class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        response = []

        if root:
            response += [root.val]

            if root.left:
                response += self.preorderTraversal(root.left)

            if root.right:
                response += self.preorderTraversal(root.right)

        return response

r1 = TreeNode(1, None, TreeNode(2, TreeNode(3)))
solution = Solution()
print(solution.preorderTraversal(root = r1))