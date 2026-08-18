#include <print>
#include <vector>

using namespace std;

#define ull unsigned long long

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {

    }
};
int main() {
    auto s = Solution();

    print("{}\n", s.numTrees(3)); //5
    print("{}\n", s.numTrees(1)); //1
    print("{}\n", s.numTrees(19)); //1767263190
}
