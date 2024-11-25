#include <iostream>
#include <unordered_map>


using std::cout, std::endl;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
};

class Solution {
public:
    int rob(const TreeNode *root) {
        if (root == nullptr) return 0;
        if (memo.find(root) != memo.end()) return memo[root];

        TreeNode *grandson_left_left = nullptr;
        if (root->left) grandson_left_left = root->left->left;
        TreeNode *grandson_left_right = nullptr;
        if (root->left) grandson_left_right = root->left->right;
        TreeNode *grandson_right_left = nullptr;
        if (root->right) grandson_right_left = root->right->left;
        TreeNode *grandson_right_right = nullptr;
        if (root->right) grandson_right_right = root->right->right;

        memo[root] = std::max(
            root->val + rob(grandson_left_left) + rob(grandson_left_right) + rob(grandson_right_left) + rob(
                grandson_right_right),
            rob(root->left) + rob(root->right)
        );

        return memo[root];
    }
private:
    std::unordered_map<const TreeNode*, int> memo;
};

int main() {
    auto s = Solution();
    // const auto a = new TreeNode(3, new TreeNode(2, nullptr, new TreeNode(3)),
    //                             new TreeNode(3, nullptr, new TreeNode(1)));
    const auto a = new TreeNode(3, new TreeNode(4, new TreeNode(1), new TreeNode(3)),
                                new TreeNode(5, nullptr, new TreeNode(1)));
    cout << s.rob(a) << endl;
    delete a;
}
