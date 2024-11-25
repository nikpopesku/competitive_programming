from typing import Optional
from listnode import ListNode, create_single_linked_list

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1 and not list2:
            return list1

        if (list1 and list2 and list1.val <= list2.val) or not list2:
            merged_head = list1
            list1 = list1.next
        else:
            merged_head = list2
            list2 = list2.next

        current_iterator = merged_head

        while list1 and list2:
            if list1.val <= list2.val:
                current_iterator.next = list1
                list1 = list1.next
                current_iterator = current_iterator.next
            else:
                current_iterator.next = list2
                list2 = list2.next
                current_iterator = current_iterator.next

        current_iterator.next = list1 if list1 else list2

        return merged_head



solution = Solution()
l1 = create_single_linked_list([])
l2 = create_single_linked_list([1])
solution.mergeTwoLists(list1 = l1, list2 = l2).print()