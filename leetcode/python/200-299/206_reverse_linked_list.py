from typing import Optional
from listnode import ListNode, create_single_linked_list

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or (head and not head.next):
            return head


        penultimate = head
        iterator = head.next
        last = None

        while iterator:
            last = iterator
            iterator = iterator.next
            last.next = penultimate
            if penultimate is head:
                penultimate.next = None
            penultimate = last

        return iterator if iterator else last



solution = Solution()
l1 = create_single_linked_list([])
solution.reverseList(head = l1).print()