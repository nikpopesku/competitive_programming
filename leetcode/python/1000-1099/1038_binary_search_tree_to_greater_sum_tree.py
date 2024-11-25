
from treenode import TreeNode


class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        root, _ = Solution.dfs(root, None)

        return root

    @staticmethod
    def dfs(node: TreeNode, sumOfBiggerKeys) -> tuple:
        current_sum = sumOfBiggerKeys if sumOfBiggerKeys else 0

        if node.right:
            _, current_sum = Solution.dfs(node.right, current_sum)

        node.val = node.val + current_sum
        current_sum = node.val

        if node.left:
            _, current_sum = Solution.dfs(node.left, node.val)

        return node, current_sum


solution = Solution()
print(solution.bstToGst(root = TreeNode(0, None, TreeNode(1))))