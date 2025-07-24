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

class Solution {
public:
    int minCameraCover(TreeNode* root) {

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

    const int response = s.minCameraCover(t);
    cout << response << " ";

    delete left_left;
    delete left_right;
    delete right;
    delete left;
    delete t;
}
