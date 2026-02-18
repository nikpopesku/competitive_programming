#include <iostream>
#include <ranges>
#include <unordered_map>
#include <unordered_set>
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
    TreeNode *createBinaryTree(const vector<vector<int> > &descriptions) {
        unordered_map<int, TreeNode *> mp;
        unordered_set<int> children;

        for (auto& d: descriptions) {
            TreeNode *parent;
            TreeNode *child;

            if (mp.contains(d[0])) {
                parent = mp[d[0]];
            } else {
                parent = new TreeNode(d[0]);
            }

            if (mp.contains(d[1])) {
                child = mp[d[1]];
            } else {
                child = new TreeNode(d[1]);
            }

            mp[d[0]] = parent;
            mp[d[1]] = child;
            children.insert(d[1]);

            if (d[2] == 1) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        }

        TreeNode *root = nullptr;

        for (const auto fst: mp | views::keys) {
            if (!children.contains(fst)) {
                root = mp[fst];
                break;
            }
        }

        return root;
    }
};

int main() {
    Solution s;

    vector<vector<int> > descriptions = {{20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};
    s.createBinaryTree(descriptions);

    return 0;
}
