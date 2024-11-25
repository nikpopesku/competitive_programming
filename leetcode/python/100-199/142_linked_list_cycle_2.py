from typing import Optional
from listnode import ListNode

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow, fast = head, head

        while fast and fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

            if slow is fast:
                fast = head
                length = Solution.getLength(slow)
                for i in range(length):
                    fast = fast.next

                slow = head

                while slow is not fast:
                    slow = slow.next
                    fast = fast.next

                return slow

        return None

    @staticmethod
    def getLength(node: Optional[ListNode]) -> int:
        start, forward = node, node.next
        counter = 1

        while start is not forward:
            counter += 1
            forward = forward.next

        return counter



solution = Solution()
print(solution.nthUglyNumber(n = 268))