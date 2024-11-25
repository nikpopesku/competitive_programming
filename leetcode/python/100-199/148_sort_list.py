from typing import Optional
from treenode import Node
from listnode import ListNode


class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head

        slow, fast = head, head.next

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        start = slow.next
        slow.next = None

        return Solution.merge(self.sortList(head), self.sortList(start))

    @staticmethod
    def merge(left: Optional[ListNode], right: Optional[ListNode]):
        if not left and not right:
            return None

        head = node = ListNode(0)

        while left or right:
            if not left:
                right, node.next = right.next, right
            elif not right:
                left, node.next = left.next, left
            else:
                if left.val < right.val:
                    left, node.next = left.next, left
                else:
                    right, node.next = right.next, right
            node = node.next

        return head.next


solution = Solution()
print(solution.sortList(head = ListNode(4, ListNode(2, ListNode(1, ListNode(3))))))