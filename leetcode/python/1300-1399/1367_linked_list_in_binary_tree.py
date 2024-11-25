
from typing import Optional
from listnode import ListNode
from treenode import TreeNode


class Solution:
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        if not head:
            return True

        if not root:
            return False

        if Solution.dfs(head, root):
            return True

        return self.isSubPath(head, root.left) or self.isSubPath(head, root.right)

    @staticmethod
    def dfs(head: Optional[ListNode], root: Optional[TreeNode]):
        if not head:
            return True

        if not root:
            return False

        if root.val == head.val:
            return Solution.dfs(head.next, root.left) or Solution.dfs(head.next, root.right)

        return False

listNode = ListNode(1, ListNode(4, ListNode(2, ListNode(6, ListNode(8)))))
root = TreeNode(1, TreeNode(4, None, TreeNode(2, TreeNode(1))), TreeNode(4, TreeNode(2, TreeNode(6), TreeNode(8, TreeNode(1), TreeNode(3)))))
solution = Solution()
print(solution.isSubPath(head = listNode, root = root))