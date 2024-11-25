from typing import Optional
from listnode import ListNode, create_single_linked_list
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        iterator = head

        while iterator:
            temp = iterator if iterator.next else None
            while temp and temp.val == iterator.val:
                temp = temp.next
            iterator.next = temp
            iterator = iterator.next

        return head




solution = Solution()
l1 = create_single_linked_list([1,1,2])
solution.deleteDuplicates(head = l1).print()