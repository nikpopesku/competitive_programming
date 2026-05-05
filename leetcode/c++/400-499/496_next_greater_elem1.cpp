#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    }
};

int main() {
    auto s = Solution();

    for (vector<int> nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2}; const auto e: s.nextGreaterElement(nums1, nums2))
        cout << e << ' ';
    cout << '\n';

    for (vector<int> nums1 = {2, 4}, nums2 = {1, 2, 3, 4}; const auto e: s.nextGreaterElement(nums1, nums2))
        cout << e << ' ';
    cout << '\n';
}
