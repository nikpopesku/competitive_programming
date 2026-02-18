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

        for (const auto &d: descriptions) {
            auto [pit, _1] = mp.try_emplace(d[0], nullptr);
            if (_1) pit->second = new TreeNode(d[0]);

            auto [cit, _2] = mp.try_emplace(d[1], nullptr);
            if (_2) cit->second = new TreeNode(d[1]);
            children.insert(d[1]);

            if (d[2] == 1) {
                pit->second->left = cit->second;
            } else {
                pit->second->right = cit->second;
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
