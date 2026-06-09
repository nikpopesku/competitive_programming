#include <iostream>
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
        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});
        unordered_map<int, unordered_map<TreeNode*, vector<int>> > mp;

        while (!st.empty()) {
            TreeNode* node = st.top().first;
            const int level = st.top().second;
            mp[level][node].push_back(node->val);
            st.pop();
            if (node->left) {
                st.push({node->left, level + 1});
            }

            if (node->right) {
                st.push({node->right, level + 1});
            }
        }

        st.push({root, 0});

        auto new_root = new TreeNode(0);


        return new_root;
    }
};

int main() {
    auto sol = Solution();

    // [4,10,24,36,56]
    for (vector<int> nums{2, 3, 7, 5, 10}; const auto &e: sol.findPrefixScore(nums)) {
        cout << e << ' ';
    }
    cout << '\n';

    // [2,4,8,16,32,64]
    for (vector<int> nums{1, 1, 2, 4, 8, 16}; const auto &e: sol.findPrefixScore(nums)) {
        cout << e << ' ';
    }
}
