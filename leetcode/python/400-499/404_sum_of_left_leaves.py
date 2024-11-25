from typing import Optional
from treenode import TreeNode

class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        queue = [root] if root else []
        left_list = []
        while queue:
            element = queue.pop(0)
            if element:
                if element.left:
                    queue.append(element.left)
                    if element.left.left is None and element.left.right is None:
                        left_list.append(element.left.val)
                if element.right:
                    queue.append(element.right)

        return sum(left_list)

solution = Solution()
print(solution.sumOfLeftLeaves(root = TreeNode(3, TreeNode(9, None, None),TreeNode(20, TreeNode(15, None, None), TreeNode(7, None, None)))))