#include <iostream>
#include <vector>
#include <algorithm>


using std::cout, std::endl;
//using std::max;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        return 4;
    }
};

int main() {
    auto s = Solution();
    cout << s.rob({3,2,3,nullptr,3,nullptr,1}) << endl;
}
