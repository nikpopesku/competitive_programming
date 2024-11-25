import sys
from typing import Optional
from math import ceil

class LinkedList:
    def __init__(self, nodes=None):
        self.head = None
        if nodes is not None:
            node = ListNode(val=nodes.pop(0))
            self.head = node
            for elem in nodes:
                node.next = ListNode(val=elem)
                node = node.next

    def get_head(self):
        return self.head

    def __repr__(self):
        node = self.head
        nodes = []
        while node is not None:
            nodes.append(node.val)
            node = node.next
        nodes.append("None")
        return " -> ".join(nodes)

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __repr__(self):
        return self.val

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        node = head
        length = 0
        while node:
            length += 1
            node = node.next

        if n == length:
            head = head.next
            return head

        node = head
        index = 1

        while index <= length - n + 1:
            previous = node
            node = node.next
            index += 1
            if index == length - n + 1:
                previous.next = node.next
                break


        return head

solution = Solution()
llist = LinkedList(['1'])
print(llist)
solution.removeNthFromEnd(llist.get_head(), 1)
print(llist)
