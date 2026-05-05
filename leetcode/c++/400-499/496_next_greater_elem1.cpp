#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        int n = static_cast<int>(nums2.size());
        vector<int> next_greater(n, -1);
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums2[st.top()] <= nums2[i]) {
                const int index = st.top();
                st.pop();
                next_greater[index] = i;
            }
            st.push(i);
        }
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
