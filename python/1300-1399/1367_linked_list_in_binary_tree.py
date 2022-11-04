
from typing import Optional
from listnode import ListNode
from treenode import TreeNode


class Solution:
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        response = False
        responseLeft = False
        responseRight = False

        if root and head and root.val == head.val:
            response = True
            head = head.next

        if root.left and head:
            responseLeft = self.isSubPath(head, root.left)

        if root.right and head and not responseLeft:
            responseRight = self.isSubPath(head, root.right)

        return (response and head is None) or (responseLeft or responseRight)

listNode = ListNode(1, ListNode(4, ListNode(2, ListNode(6, ListNode(8)))))
root = TreeNode(1, TreeNode(4, None, TreeNode(2, TreeNode(1))), TreeNode(4, TreeNode(2, TreeNode(6), TreeNode(8, TreeNode(1), TreeNode(3)))))
solution = Solution()
print(solution.isSubPath(head = listNode, root = root))