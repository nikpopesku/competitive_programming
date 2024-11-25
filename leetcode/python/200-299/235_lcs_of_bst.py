from typing import Optional, List
from treenode import TreeNode

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if p.val == root.val or q.val == root.val:
            return root

        if (p.val > root.val and q.val < root.val) or (p.val < root.val and q.val > root.val):
            return root

        if p.val < root.val and q.val < root.val:
            return self.lowestCommonAncestor(root.left, p, q)

        return self.lowestCommonAncestor(root.right, p, q)



r1 = TreeNode(18, TreeNode(2), TreeNode(22, None, TreeNode(63, None, TreeNode(84))))
solution = Solution()
print(solution.lowestCommonAncestor(root = r1, p = TreeNode(2), q = TreeNode(8)))