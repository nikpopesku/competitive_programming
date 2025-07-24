#include <iostream>
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

class Solution
{
public:
    static int diameterOfBinaryTree(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        vector<TreeNode*> stack;
        int max_value = 0;
        dfs(root, stack, max_value);

        return max_value;
    }

    static int dfs(TreeNode* node, vector<TreeNode*>& stack, int& max_value)
    {
        stack.push_back(node);
        int answer = 0;
        int left = 0;
        int right = 0;

        if (node->left)
        {
            left = dfs(node->left, stack, max_value) + 1;
        }

        if (node->right)
        {
            right = dfs(node->right, stack, max_value) + 1;
        }

        answer = max(left, right);

        stack.pop_back();

        max_value = max(max_value, left + right);

        return answer;
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
