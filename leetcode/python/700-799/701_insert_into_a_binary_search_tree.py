from typing import Optional, List
from treenode import TreeNode

class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if root is None:
            return TreeNode(val)

        parent = root
        found = False
        while not found:
            if parent.val < val:
                if parent.right:
                    parent = parent.right
                else:
                    found = True

            if parent.val > val:
                if parent.left:
                    parent = parent.left
                else:
                    found = True


        if parent.val > val:
            parent.left = TreeNode(val)

        if parent.val < val:
            parent.right = TreeNode(val)

        return root


r1 = TreeNode(18, TreeNode(2), TreeNode(22, None, TreeNode(63, None, TreeNode(84))))
solution = Solution()
print(solution.insertIntoBST(root = r1, val = 5))