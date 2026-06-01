#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;


class Solution {
public:
    int trap(vector<int> &height) {
    }
};


int main() {
    auto s = Solution();

    vector nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << s.trap(nums) << endl; //6

    vector nums2 = {4, 2, 0, 3, 2, 5};
    cout << s.trap(nums2) << endl;
}
