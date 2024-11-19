#include <iostream>
#include "../library/treenode.h"
#include <unordered_map>
#include <climits>


using std::cout, std::endl;

// auto hash = [](const TreeNode& n){return std::hash<const TreeNode*>()(&n);};
// auto equal = [](const TreeNode& l, const TreeNode& r){return l.val == r.val;};


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
    // cout << s.maxPathSum(new TreeNode(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)))) << endl;
    cout << s.maxPathSum(new TreeNode(1, new TreeNode(-2, new TreeNode(1, new TreeNode(-1), nullptr), new TreeNode(3)), new TreeNode(-3, new TreeNode(-2), nullptr))) << endl;
    // cout << s.maxPathSum(new TreeNode(-3)) << endl;
}
