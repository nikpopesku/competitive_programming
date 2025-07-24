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
    static int minCameraCover(const TreeNode* root)
    {
        int min_cameras = 0;
        dfs(root, nullptr, min_cameras);

        return min_cameras;
    }

    static bool dfs(const TreeNode* node, const TreeNode* parent, int& min_cameras)
    {
        if (node == nullptr)
        {
            return false;
        }

        const bool left = dfs(node->left, node, min_cameras);
        const bool right = dfs(node->right, node, min_cameras);

        if ((node->left || node->right) && !left && !right)
        {
            ++min_cameras;

            return true;
        }

        if (parent == nullptr)
        {
            ++min_cameras;
        }

        return false;
    }
};


int main()
{
    auto* node4 = new TreeNode(0);
    auto* node3 = new TreeNode(0, nullptr, node4);
    auto* node2 = new TreeNode(0, nullptr, node3);
    auto* node1 = new TreeNode(0, nullptr, node2);

    cout << Solution::minCameraCover(node1) << " ";

    delete node1;

    auto* leftGrandchild = new TreeNode(0);
    auto* rightGrandchild = new TreeNode(0);
    auto* leftChild = new TreeNode(0, leftGrandchild, rightGrandchild);
    auto* root = new TreeNode(0, leftChild, nullptr);

    cout << Solution::minCameraCover(root) << " ";

    delete root;
}
