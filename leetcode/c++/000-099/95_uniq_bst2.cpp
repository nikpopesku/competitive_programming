#include <print>
#include <string>
#include <vector>

using namespace std;

#define ull unsigned long long

/**
 * Definition for a binary tree node.
 **/

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
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> v;
        TreeNode t;
        TreeNode *cur_variant = &t;
        backtrack(v, cur_variant, 1, n);

        return v;
    }

private:
    void backtrack(vector<TreeNode *> &v, TreeNode *cur_variant, int start, int n) {
        if (start == n) {
            v.push_back(cloneTree(cur_variant));

            return;
        }

        cur_variant->left = new TreeNode(start + 1);
        backtrack(v, cur_variant, start + 1, n);
        cur_variant->left = nullptr;

        cur_variant->right = new TreeNode(start + 1);
        backtrack(v, cur_variant, start + 1, n);
        cur_variant->right = nullptr;
    }

    TreeNode* cloneTree(TreeNode *node) {
        if (!node) return nullptr;
        return new TreeNode(node->val, cloneTree(node->left), cloneTree(node->right));
    }
};

void printTree(TreeNode *node, const string &prefix = "", bool isLast = true) {
    if (!node) {
        return;
    }

    println("{}{}{}", prefix, isLast ? "└── " : "├── ", node->val);

    string childPrefix = prefix + (isLast ? "    " : "│   ");
    if (node->left) {
        printTree(node->left, childPrefix, !node->right);
    }
    if (node->right) {
        printTree(node->right, childPrefix, true);
    }
}

int main() {
    auto s = Solution();
    auto trees = s.generateTrees(3);

    for (size_t i = 0; i < trees.size(); ++i) {
        println("Tree {}:", i + 1);
        printTree(trees[i]);
        println("");
    }
}
