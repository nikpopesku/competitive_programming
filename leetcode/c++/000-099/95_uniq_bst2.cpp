#include <print>
#include <vector>

using namespace std;

#define ull unsigned long long

/**
 * Definition for a binary tree node.
 **/

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
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> v;
        TreeNode *cur_variant{};
        backtrack(v, cur_variant, 1, n);

        return v;
    }

private:
    void backtrack(vector<TreeNode *> &v, TreeNode *cur_variant, int start, int n) {
        if (start == n) {
            v.push_back(cur_variant);
        }

        cur_variant->left = new TreeNode(start + 1);
        backtrack(v, cur_variant, start + 1, n);
        cur_variant->left = nullptr;

        cur_variant->right = new TreeNode(start + 1);
        backtrack(v, cur_variant, start + 1, n);
        cur_variant->right = nullptr;
    }
};

int main() {
    auto s = Solution();

    print("{}\n", s.generateTrees(3));
}
