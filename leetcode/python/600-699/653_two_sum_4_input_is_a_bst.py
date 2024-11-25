from typing import Optional, List
from treenode import TreeNode

class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        if not root:
            return False

        hash = {}
        stack = [root]

        while len(stack) != 0:
            element = stack.pop(0)
            if k - element.val in hash:
                return True
            else:
                hash[element.val] = k - element.val

            if element.left:
                stack.append(element.left)

            if element.right:
                stack.append(element.right)


        return False


r1 = TreeNode(5, TreeNode(4), TreeNode(8, TreeNode(7, TreeNode(6)), TreeNode(9)))
solution = Solution()
print(solution.findTarget(root = r1, k = 9))