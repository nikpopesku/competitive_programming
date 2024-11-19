
#include <iostream>
#include <unordered_map>
#include "../library/treenode.h"


using std::cout, std::endl;


class Solution {
public:
    int maxPathSum(TreeNode* root) {
        return 4;
    }
};

int main() {
    auto s = Solution();
    // const auto a = new TreeNode(3, new TreeNode(2, nullptr, new TreeNode(3)),
    //                             new TreeNode(3, nullptr, new TreeNode(1)));
    const auto a = new TreeNode(3, new TreeNode(4, new TreeNode(1), new TreeNode(3)),
                                new TreeNode(5, nullptr, new TreeNode(1)));
    cout << s.maxPathSum(a) << endl;
    delete a;
}
