#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = static_cast<int>(heights.size());
        vector<int> min_right = heights;
        stack<int> st;
        int max_area = *max_element(heights.begin(), heights.end());

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int index = st.top();
                st.pop();
                min_right[index] = heights[i];
            }
            if (!st.empty()) {
                max_area = max(max_area, (i - st.top() + 1) * heights[st.top()]);
            }
            st.push(i);
        }

        for (int i = 0; i < n; ++i) {
            max_area = max(max_area, min_right[i] * (n - i));
        }

        return max_area;
    }
};

int main() {
    auto s = Solution();

    vector<int> nums = {2, 1, 5, 6, 2, 3};
    cout << s.largestRectangleArea(nums) << '\n';

    vector<int> nums2 = {2, 4};
    cout << s.largestRectangleArea(nums2) << '\n';
}
