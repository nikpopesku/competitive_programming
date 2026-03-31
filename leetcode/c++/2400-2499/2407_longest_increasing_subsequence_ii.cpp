#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int lengthOfLIS(const vector<int> &nums, const int k) {
    }
};

int main() {
    auto sol = Solution();

    // Example 1: expected 5  (subsequence 1->2->3->4->5 or 2->3->4->5->8 etc.)
    cout << sol.lengthOfLIS({4, 2, 1, 4, 3, 4, 5, 8, 15}, 3) << "\n";

    // Example 2: expected 4  (subsequence 1->3->5->7)
    cout << sol.lengthOfLIS({7, 4, 5, 1, 8, 12, 4, 7}, 5) << "\n";

    // Example 3: expected 1  (no two elements are within k=1 gap)
    cout << sol.lengthOfLIS({1, 5}, 1) << "\n";
}
