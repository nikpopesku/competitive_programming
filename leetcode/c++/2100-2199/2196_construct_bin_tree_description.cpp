#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;


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
    TreeNode *createBinaryTree(vector<vector<int> > &descriptions) {
    }
};

int main() {
    Solution s;

    vector<int> a = {1, 0, 3, -1};
    vector<int> b = {-1, -1, -1, -1};
    cout << boolalpha << s.validateBinaryTreeNodes(4, a, b);

    return 0;
}
