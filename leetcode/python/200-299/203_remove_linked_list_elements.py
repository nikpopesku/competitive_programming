from typing import Optional
from listnode import ListNode, create_single_linked_list

class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        while head and head.val == val:
            head = head.next

        iterator = head

        while iterator:
            next_val = iterator.next
            while next_val and next_val.next and next_val.val == val:
                next_val = next_val.next
            iterator.next = next_val if next_val and next_val.val != val else None
            iterator = iterator.next

        return head


solution = Solution()
l1 = create_single_linked_list([1,2,6,3,4,5,6])
solution.removeElements(head = l1, val = 6).print()