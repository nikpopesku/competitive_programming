from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def print(self):
        nodes = []
        nodes.append(str(self.val))
        node = self

        while node.next:
            node = node.next
            nodes.append(str(node.val))

        print(" -> ".join(nodes))


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        next = ListNode((l1.val + l2.val) % 10, None)
        carret = (l1.val + l2.val) // 10
        l1 = l1.next
        l2 = l2.next
        while l1 is not None or l2 is not None:
            value1 = 0 if l1 is None else l1.val
            value2 = 0 if l2 is None else l2.val
            next = ListNode((value1 + value2 + carret) % 10, next)
            carret = (value1 + value2 + carret) // 10
            l1 = None if l1 is None or l1.next is None else l1.next
            l2 = None if l2 is None or l2.next is None else l2.next

        if carret > 0:
            next = ListNode(carret, next)

        reversed_next = ListNode(next.val, None)
        next = next.next
        while next:
            reversed_next = ListNode(next.val, reversed_next)
            next = next.next

        return reversed_next



def create_single_linked_list(arr):
    next = None
    for key, value in enumerate(reversed(arr)):
        next = ListNode(value, next)

    return next


solution = Solution()
l1 = create_single_linked_list([9,9,9,9,9,9,9])
l2 = create_single_linked_list([9,9,9,9])

solution.addTwoNumbers(l1, l2).print()