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
    Solution s;

    TreeNode* left_left = new TreeNode(0);
    TreeNode* left_right = new TreeNode(0);
    TreeNode* left = new TreeNode(0, left_left, left_right);
    TreeNode* t = new TreeNode(0, left, nullptr);

    const int response = s.minCameraCover(t);
    cout << response << " ";

    delete left_left;
    delete left_right;
    delete left;
    delete t;
}
