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
    vector<TreeNode*> generateTrees(int n) {

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
