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
        stack<pair<TreeNode *, int> > st;
        st.push({root, 0});
        unordered_map<int, unordered_map<TreeNode *, vector<int> > > mp;

        while (!st.empty()) {
            TreeNode *node = st.top().first;
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

        stack<tuple<TreeNode *, TreeNode*, int> > sstt;
        auto new_root = new TreeNode(0);
        sstt.push({root, new_root, 0});

        while (!sstt.empty()) {
            auto node = std::get<0>(sstt.top());
            auto new_node = std::get<1>(sstt.top());
            int level = std::get<2>(sstt.top());
            st.pop();

            if (!mp[level].contains(node)) {
                new_node->val = 0;
            } else {
                int cousins_val = 0;
                for (auto &[fst, snd]: mp[level]) {
                    if (fst != node) {
                        for (const auto &x: snd) {
                            cousins_val += x;
                        }
                    }
                }

                new_node->val = cousins_val;
            }

            if (node->left) {
                TreeNode new_left(0);
                new_node->left = &new_left;
                sstt.push({node->left, &new_left, level + 1});
            }

            if (node->right) {
                TreeNode new_right(0);
                new_node->left = &new_right;
                sstt.push({node->right, &new_right, level + 1});
            }
        }


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
