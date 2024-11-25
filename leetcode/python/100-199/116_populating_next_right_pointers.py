from typing import Optional, List
from treenode import Node

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        def inner_connect(node):
            if node and node.left:
                node.left.next = node.right
                inner_connect(node.left)

            if node and node.right:
                if node.next:
                    node.right.next = node.next.left
                inner_connect(node.right)

            return node

        return inner_connect(root)


r1 = Node(1, None, Node(2, Node(3)))
solution = Solution()
print(solution.connect(root = r1))