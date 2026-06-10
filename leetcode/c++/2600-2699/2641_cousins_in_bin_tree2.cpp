#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
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
    TreeNode *replaceValueInTree(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        root->val = 0;

        while (!q.empty()) {
            int sz = static_cast<int>(q.size());
            vector<TreeNode *> level_nodes;
            level_nodes.reserve(sz);
            for (int i = 0; i < sz; ++i) {
                level_nodes.push_back(q.front());
                q.pop();
            }

            int next_sum = 0;
            for (auto *node : level_nodes) {
                if (node->left) next_sum += node->left->val;
                if (node->right) next_sum += node->right->val;
            }

            for (auto *node : level_nodes) {
                int sibling_sum = (node->left ? node->left->val : 0)
                                + (node->right ? node->right->val : 0);
                if (node->left) {
                    node->left->val = next_sum - sibling_sum;
                    q.push(node->left);
                }
                if (node->right) {
                    node->right->val = next_sum - sibling_sum;
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};

TreeNode *buildTree(const vector<int> &vals, int null_val = -1) {
    if (vals.empty() || vals[0] == null_val) return nullptr;
    auto *root = new TreeNode(vals[0]);
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < (int) vals.size()) {
        auto *node = q.front();
        q.pop();
        if (i < (int) vals.size() && vals[i] != null_val) {
            node->left = new TreeNode(vals[i]);
            q.push(node->left);
        }
        ++i;
        if (i < (int) vals.size() && vals[i] != null_val) {
            node->right = new TreeNode(vals[i]);
            q.push(node->right);
        }
        ++i;
    }
    return root;
}

void printTree(TreeNode *root) {
    if (!root) { cout << "[]\n"; return; }
    queue<TreeNode *> q;
    q.push(root);
    cout << '[';
    bool first = true;
    while (!q.empty()) {
        auto *node = q.front();
        q.pop();
        if (!first) cout << ',';
        first = false;
        if (!node) { cout << "null"; continue; }
        cout << node->val;
        q.push(node->left);
        q.push(node->right);
    }
    cout << "]\n";
}

int main() {
    auto sol = Solution();

    // [0,0,0,7,7,null,11]
    printTree(sol.replaceValueInTree(buildTree({5, 4, 9, 1, 10, -1, 7})));

    // [0,0,0]
    printTree(sol.replaceValueInTree(buildTree({3, 1, 2})));
}
