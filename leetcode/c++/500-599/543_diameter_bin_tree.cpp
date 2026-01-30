#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right)
    {
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int maxvalue = 0;
        stack<TreeNode*> st;

        dfs(root, maxvalue, st);

        return maxvalue;
    }

private:
    int dfs(TreeNode* node, int& maxvalue, stack<TreeNode*>& st) {
        int left = 0;
        int right = 0;

        st.push(node);

        if (node->left) {
            left = 1 + dfs(node->left, maxvalue, st);
        }

        if (node->right) {
            right = 1 + dfs(node->right, maxvalue, st);
        }

        st.pop();

        maxvalue = max(maxvalue, left + right);

        return maxvalue;
    }
};

int main()
{
    Solution s;

    TreeNode* right = new TreeNode(3);
    TreeNode* left_left = new TreeNode(4);
    TreeNode* left_right = new TreeNode(5);
    TreeNode* left = new TreeNode(2, left_left, left_right);
    TreeNode* t = new TreeNode(1, left, right);

    const int response = s.diameterOfBinaryTree(t);
    cout << response << " ";

    delete left_left;
    delete left_right;
    delete right;
    delete left;
    delete t;
}
