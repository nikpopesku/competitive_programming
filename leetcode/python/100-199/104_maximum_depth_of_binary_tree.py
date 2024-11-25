from typing import Optional
from treenode import TreeNode

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        queue = [root] if root and isinstance(root.val, int) else []
        level = 0
        n = len(queue)

        while n != 0:
            level += 1
            i = 0
            new_queue = []

            while i < n:
                if queue[i]:
                    if queue[i].left:
                        new_queue.append(queue[i].left)

                    if queue[i].right:
                        new_queue.append(queue[i].right)

                i += 1

            queue = new_queue
            n = len(queue)

        return level


root = TreeNode(0)

solution = Solution()
print(solution.maxDepth(root = root))