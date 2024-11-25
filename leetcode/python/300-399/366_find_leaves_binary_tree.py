
import sys
from typing import List
from typing import Optional
from treenode import TreeNode


class Solution:
    def findLeaves(self, root: Optional[TreeNode]) -> List[List[int]]:
        response = []
        last = Solution.findLeavesInternal(root)

        while last:
            response.append(last)
            last = Solution.findLeavesInternal(root)

        response.append([root.val])

        return response

    @staticmethod
    def findLeavesInternal(root: Optional[TreeNode]) -> List:
        if not root:
            return []

        stack = [(root, None, None)]
        temp = []

        while stack:
            element, parent, part = stack.pop()
            pushed = False
            if element.left:
                stack.append((element.left, element, 'left'))
                pushed = True
            if element.right:
                stack.append((element.right, element, 'right'))
                pushed = True
            if not pushed:
                if element != root:
                    temp.append(element.val)
                if part == 'left':
                    parent.left = None
                elif part == 'right':
                    parent.right = None

        return temp

solution = Solution()
print(solution.findLeaves(root=TreeNode(1, TreeNode(2, TreeNode(4), TreeNode(5)), TreeNode(3))))