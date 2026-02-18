#include <iostream>
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
    TreeNode *createBinaryTree(const vector<vector<int> > &descriptions) {
        for (auto d: descriptions) {
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
            ++indegree[d[1]];

            if (d[2] == 1) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        }

        TreeNode *root = nullptr;

        for (auto elem: indegree) {
            if (elem.second == 0) {
                root = mp[elem.first];
            }
        }

        return root;
    }

private:
    unordered_map<int, TreeNode *> mp;
    unordered_map<int, int> indegree;
};

int main() {
    Solution s;

    vector<vector<int> > descriptions = {{20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};
    s.createBinaryTree(descriptions);

    return 0;
}
