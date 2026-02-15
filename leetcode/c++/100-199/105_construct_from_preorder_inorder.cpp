#include <string>
#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }

    explicit TreeNode(const int x) : val(x), left(nullptr), right(nullptr) {
    }

    TreeNode(const int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
};

class Solution {
public:
    TreeNode *buildTree(const vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty()) {
            return nullptr;
        }

        TreeNode root(preorder[0]);
        int counter = 0;

        while (counter < static_cast<int>(inorder.size())) {
            if (inorder[counter] == preorder[0]) {
                break;
            }

            ++counter;
        }

        const vector new_inorder(inorder.begin(), inorder.begin() + counter);

        root.left = buildTree(preorder, new_inorder);

        return root;
    }
};


int main() {
    auto s = Solution();
    vector preorder = {3, 9, 20, 15, 7};
    vector inorder = {9, 3, 15, 20, 7};
    cout << s.buildTree(preorder, inorder) << endl;
}
