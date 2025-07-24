#include <iostream>

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
//states: 0 - not covered; 1 - has camera; 2 - is covered
class Solution
{
public:
    static int minCameraCover(const TreeNode* root)
    {
        int min_cameras = 0;
        if (dfs(root, min_cameras) == 0)
        {
            ++min_cameras;
        }

        return min_cameras;
    }

private:
    static int dfs(const TreeNode* node, int& min_cameras)
    {
        if (node == nullptr)
        {
            return 2;
        }

        const int left = dfs(node->left, min_cameras);
        const int right = dfs(node->right, min_cameras);

        if (left == 0 || right == 0)
        {
            ++min_cameras;

            return 1;
        }

        if (left == 1 || right == 1)
        {
            return 2;
        }

        return 0;
    }
};


int main()
{
    auto* node4 = new TreeNode(0);
    auto* node3 = new TreeNode(0, nullptr, node4);
    auto* node2 = new TreeNode(0, nullptr, node3);
    const auto* root = new TreeNode(0, nullptr, node2);

    cout << Solution::minCameraCover(root) << " ";

    delete root;

    auto* leftGrandchild = new TreeNode(0);
    auto* rightGrandchild = new TreeNode(0);
    auto* leftChild = new TreeNode(0, leftGrandchild, rightGrandchild);
    root = new TreeNode(0, leftChild, nullptr);

    cout << Solution::minCameraCover(root) << " ";

    delete root;
}
