from typing import Optional, List
from treenode import TreeNode

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        levels = {}

        queue = [root]
        level = 0

        while len(queue) != 0:
            level += 1
            subarray = []
            n = len(queue)
            i = 0

            while i < n:
                element = queue[0]
                queue = queue[1:]

                if element:
                    subarray.append(element.val)

                    if element.left:
                        queue.append(element.left)

                    if element.right:
                        queue.append(element.right)

                i += 1

            if subarray:
                levels[level] = subarray

        return [list(val) for val in levels.values()]


root = TreeNode(3)
root.left = TreeNode(9)
root.right = TreeNode(20)
root.right.left = TreeNode(15)
root.right.right = TreeNode(7)

solution = Solution()
print(solution.levelOrder(root = root))