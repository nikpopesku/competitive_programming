#include <iostream>
#include "../library/treenode.h"
#include <unordered_map>
#include <climits>


using std::cout, std::endl;


class Solution {
public:
    int maxPathSum(TreeNode *root) {
        if (root == nullptr) return INT_MIN;
        if (dp.find(root->val) != dp.end()) return dp[root->val];

        if (root->left == nullptr and root->right == nullptr) {
            dp[root->val] = root->val;
        }

        const long long left = maxPathSum(root->left);
        const long long right = maxPathSum(root->right);
        dp[root->val] = max({left, right, left + right + root->val, root->val, left + root->val, right + root->val});

        return dp[root->val];
    }

private:
    static int max(const std::initializer_list<long long> list) {
        int max_value = *list.begin();
        for (const auto elem: list) {
            if (elem > max_value) {
                max_value = elem;
            }
        }

        return max_value;
    }

    std::unordered_map<int, long long> dp{};
};

int main() {
    auto s = Solution();
    // cout << s.maxPathSum(new TreeNode(-10, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)))) << endl;
    cout << s.maxPathSum(new TreeNode(-3)) << endl;
}
