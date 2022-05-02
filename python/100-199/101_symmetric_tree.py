from typing import Optional, List
from treenode import TreeNode

class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        response = self.inorderTraversal(root.left) if root and root.left else []
        response += [root.val] if root else []
        response += self.inorderTraversal(root.right) if root and root.right else []

        return response

    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        elif root.left and not root.right or root.right and not root.left:
            return False
        elif not root.left and not root.right:
            return True

        return self.inorderTraversal(root.left) == list(reversed(self.inorderTraversal(root.right)))


root = TreeNode(1)
second_left = TreeNode(2)
second_right = TreeNode(2)
root.left = second_left
root.right = second_right
second_left.left = TreeNode(3)
second_left.right = TreeNode(4)
second_right.left = TreeNode(4)
second_right.right = TreeNode(3)

solution = Solution()
print(solution.isSymmetric(root = root))