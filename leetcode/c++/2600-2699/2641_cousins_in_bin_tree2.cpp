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
        stack<pair<TreeNode *, int> > st;
        st.emplace(root, 0);
        unordered_map<int, unordered_map<TreeNode *, vector<int> > > mp;

        while (!st.empty()) {
            TreeNode *node = st.top().first;
            const int level = st.top().second;
            mp[level][node].push_back(node->val);
            st.pop();
            if (node->left) {
                st.emplace(node->left, level + 1);
            }

            if (node->right) {
                st.emplace(node->right, level + 1);
            }
        }

        stack<tuple<TreeNode *, TreeNode*, int> > sstt;
        auto *new_root = new TreeNode(0);
        sstt.emplace(root, new_root, 0);

        while (!sstt.empty()) {
            auto node = std::get<0>(sstt.top());
            const auto new_node = std::get<1>(sstt.top());
            int level = std::get<2>(sstt.top());
            sstt.pop();

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
                auto *new_left = new TreeNode(0);
                new_node->left = new_left;
                sstt.emplace(node->left, new_left, level + 1);
            }

            if (node->right) {
                auto *new_right = new TreeNode(0);
                new_node->right = new_right;
                sstt.emplace(node->right, new_right, level + 1);
            }
        }


        return new_root;
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
