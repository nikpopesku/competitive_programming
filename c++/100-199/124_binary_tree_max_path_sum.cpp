#include <iostream>
#include "../library/treenode.h"
#include <unordered_map>


using std::cout, std::endl;


class Solution {
public:
    int maxPathSum(TreeNode *root) {
        if (root == nullptr) return 0;
        if (dp.find(root->val) != dp.end()) return dp[root->val];

        if (root->left == nullptr and root->right == nullptr) {
            dp[root->val] = root->val;
        }

        const int left = maxPathSum(root->left);
        const int right = maxPathSum(root->right);
        dp[root->val] = max({left, right, left + right + root->val, root->val, left + root->val, right + root->val});

        return dp[root->val];
    }

private:
    static int max(std::initializer_list<int> list) {
        int max_value = *list.begin();
        for (const auto elem: list) {
            if (elem > max_value) {
                max_value = elem;
            }
        }

        return max_value;
    }

    std::unordered_map<int, int> dp{};
};

int main() {
    auto s = Solution();
    cout << s.maxPathSum(new TreeNode(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)))) <<
            endl;
}
