from typing import List
from listnode import ListNode


class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        response = 0
        while head:
            response = (response << 1) | head.val
            head = head.next

        return response


solution = Solution()
print(solution.getDecimalValue(head = ListNode(1, ListNode(0, ListNode(1)))))