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
    TreeNode *buildTree(const vector<int> &preorder, const vector<int> &inorder) {
        if (preorder.empty()) {
            return nullptr;
        }

        auto* root = new TreeNode(preorder[0]);
        int counter = 0;

        while (counter < static_cast<int>(inorder.size())) {
            if (inorder[counter] == preorder[0]) {
                break;
            }

            ++counter;
        }

        const vector left_inorder(inorder.begin(), inorder.begin() + counter);
        const vector right_inorder(inorder.begin() + counter + 1, inorder.end());

        const vector left_preorder(preorder.begin() + 1, preorder.begin() + 1 + counter);
        const vector right_preorder(preorder.begin() + counter + 1, preorder.end());

        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);

        return root;
    }
};


int main() {
    auto s = Solution();
    vector preorder = {3, 9, 20, 15, 7};
    vector inorder = {9, 3, 15, 20, 7};
    cout << s.buildTree(preorder, inorder) << endl;
}
