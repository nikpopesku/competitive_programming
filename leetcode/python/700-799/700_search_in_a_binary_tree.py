from typing import Optional, List
from treenode import TreeNode

class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if root is None:
            return None

        if root.val == val:
            return root

        return self.searchBST(root.left, val) or self.searchBST(root.right, val) if root.left is not None or root.right is not None else None



r1 = TreeNode(18, TreeNode(2), TreeNode(22, None, TreeNode(63, None, TreeNode(84))))
solution = Solution()
print(solution.searchBST(root = r1, val = 2))