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
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        node = head
        counter = 0
        while node:
            counter += 1
            node = node.next

        counter = ceil((counter + 1) / 2)
        index = 1
        node = head
        while index < counter:
            node = node.next
            index += 1

        return node

solution = Solution()
llist = LinkedList(['1', '2', '3', '4', '5', '6'])
print(llist)
print(solution.middleNode(llist.get_head()))
