#include <iostream>
#include "../library/treenode.h"
#include <unordered_map>
#include <climits>


using std::cout, std::endl;

// auto hash = [](const TreeNode& n){return std::hash<const TreeNode*>()(&n);};
// auto equal = [](const TreeNode& l, const TreeNode& r){return l.val == r.val;};


class Solution {
public:

    int maxPathSum(TreeNode *root) {
        if (root == nullptr) return INT_MIN;
        if (dp.find(root) != dp.end()) return dp[root];

        if (root->left == nullptr and root->right == nullptr) {
            dp[root] = root->val;
        }

        const long long left = maxPathSum(root->left);
        const long long right = maxPathSum(root->right);
        dp[root] = max({left, right, left + right + root->val, root->val, left + root->val, right + root->val});

        return dp[root];
    }

    struct HashFunction
    {
        size_t operator()(const TreeNode& n) const
        {
            return std::hash<const TreeNode*>()(&n);
        }
    };
private:
    std::unordered_map<TreeNode*, int, HashFunction> dp {};

    int max(const std::initializer_list<long long> list) {
        int max_value = *list.begin();
        for (const auto elem: list) {
            if (elem > max_value) {
                max_value = elem;
            }
        }

        return max_value;
    }

};

int main() {
    auto s = Solution();
    // cout << s.maxPathSum(new TreeNode(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)))) << endl;
    cout << s.maxPathSum(new TreeNode(1, new TreeNode(-2, new TreeNode(1, new TreeNode(-1), nullptr), new TreeNode(3)), new TreeNode(-3, new TreeNode(-2), nullptr))) << endl;
    // cout << s.maxPathSum(new TreeNode(-3)) << endl;
}
