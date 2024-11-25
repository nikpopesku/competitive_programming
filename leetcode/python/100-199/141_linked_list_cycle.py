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
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow, fast = head, head
        while slow and slow.next and fast and fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
            if slow is fast:
                return True

        return False


def create_single_linked_list(arr):
    next = None
    for key, value in enumerate(reversed(arr)):
        next = ListNode(value, next)

    return next


solution = Solution()
l1 = ListNode(3)
l2 = ListNode(2)
l3 = ListNode(0)
l4 = ListNode(4)

l1.next = l2
l2.next = l3
l3.next = l4
l4.next = l2


print(solution.hasCycle(l1))