#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
    }
};

int main() {
    auto s = Solution();

    for (vector<int> nums1 = {1, 2, 1}; const auto e: s.nextGreaterElement(nums1))
        cout << e << ' ';
    cout << '\n';

    for (vector<int> nums1 = {1, 2, 3, 4, 3}; const auto e: s.nextGreaterElement(nums1))
        cout << e << ' ';
    cout << '\n';
}
