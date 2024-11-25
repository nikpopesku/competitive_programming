from typing import Optional, List
from treenode import TreeNode

class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def findSymmetry(p, q):
            if p and q:
                return p.val == q.val and findSymmetry(p.left, q.right) and findSymmetry(p.right, q.left)
            elif p or q:
                return False
            return True

        return findSymmetry(root.left, root.right)


root = TreeNode(1)
second_left = TreeNode(2)
second_right = TreeNode(2)
root.left = second_left
root.right = second_right
second_left.left = TreeNode(2)
second_right.left = TreeNode(2)

solution = Solution()
print(solution.isSymmetric(root = root))