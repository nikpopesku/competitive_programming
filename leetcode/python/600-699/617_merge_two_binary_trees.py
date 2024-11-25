from typing import Optional
from treenode import TreeNode

class Solution:
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root2 and not root1:
            return root1

        def parse(node1: Optional[TreeNode], node2: Optional[TreeNode]):
            new_root = TreeNode((node1.val if node1 else 0) + (node2.val if node2 else 0))
            if (node1 and node1.left) or (node2 and node2.left):
                new_root.left = parse(node1.left if node1 else None, node2.left if node2 else None)
            if (node1 and node1.right) or (node2 and node2.right):
                new_root.right = parse(node1.right if node1 else None, node2.right if node2 else None)

            return new_root



        return parse(root1, root2)






solution = Solution()
xxx = solution.mergeTrees(root1 = TreeNode(1, TreeNode(3, TreeNode(5)), TreeNode(2)), root2 = TreeNode(2, TreeNode(1, None, TreeNode(4)), TreeNode(3, None, TreeNode(7))))
yyy = 5