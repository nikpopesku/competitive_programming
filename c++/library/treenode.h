#ifndef TREENODE_H
#define TREENODE_H


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

    bool operator==(const TreeNode& otherPos) const
    {
        if (this->val == otherPos.val) return true;

        return false;
    }
};


#endif //TREENODE_H
