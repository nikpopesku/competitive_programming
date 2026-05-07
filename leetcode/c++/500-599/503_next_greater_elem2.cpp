#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        vector<int> response(n, -1);
        stack<int> st;

        for (int i = 0; i < 2 * n; ++i) {
            int j = i % n;
            while (!st.empty() && nums[st.top()] < nums[j]) {
                const int index = st.top();
                st.pop();
                response[index] = nums[j];
            }
            st.push(j);
        }

        return response;
    }
};

int main() {
    auto s = Solution();

    for (vector<int> nums1 = {1, 2, 1}; const auto e: s.nextGreaterElements(nums1))
        cout << e << ' ';
    cout << '\n';

    for (vector<int> nums1 = {1, 2, 3, 4, 3}; const auto e: s.nextGreaterElements(nums1))
        cout << e << ' ';
    cout << '\n';
}
