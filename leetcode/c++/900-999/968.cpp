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

        dfs(root, min_cameras);

        if (min_cameras == 0 && root)
        {
            ++min_cameras;
        }

        return min_cameras;
    }

    static bool dfs(const TreeNode* node, int& min_cameras)
    {
        if (node == nullptr)
        {
            return false;
        }

        const bool left = dfs(node->left, min_cameras);
        const bool right = dfs(node->right, min_cameras);

        if (left || right)
        {
            ++min_cameras;

            return false;
        }

        if (node->left || node->right)
        {
            return true;
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
    const TreeNode* root  = node1; // or just 'root' if you want to refer directly

    const int response = Solution::minCameraCover(root);
    cout << response << " ";

    delete node4;
    delete node3;
    delete node2;
    delete node1;
    delete root;
}
