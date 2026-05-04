#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
    }
};

int main() {
    auto s = Solution();

    vector<int> nums = {2, 1, 5, 6, 2, 3};
    cout << s.largestRectangleArea(nums) << '\n';

    vector<int> nums2 = {2, 4};
    cout << s.largestRectangleArea(nums) << '\n';
}
