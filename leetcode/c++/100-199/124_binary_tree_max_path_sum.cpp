#include <iostream>
#include "../library/treenode.h"
#include <climits>


using std::cout, std::endl;

class Solution {
public:

    int maxPathSum(const TreeNode *root) {
        calc(root);

        return max_value;
    }
private:
    int calc(const TreeNode *node) {
        if (node == nullptr) return 0;

        const int left = std::max(0, calc(node->left));
        const int right = std::max(0, calc(node->right));

        max_value = std::max(max_value, left + right + node->val);

        return std::max(node->val + left, node->val + right);
    }
    int max_value = INT_MIN;
};

int main() {
    auto s = Solution();
    cout << s.maxPathSum(new TreeNode(1, new TreeNode(-2, new TreeNode(1, new TreeNode(-1), nullptr), new TreeNode(3)), new TreeNode(-3, new TreeNode(-2), nullptr))) << endl;
}
