#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int max_area = 0;
        const int n = static_cast<int>(heights.size());
        stack<int> st;

        for (int i = 0; i <= n; ++i) {
            int h = i < n ? heights[i] : 0;
            while (!st.empty() && heights[st.top()] > h) {
                const int height = heights[st.top()];
                st.pop();
                const int width = st.empty() ? i : i - st.top() - 1;
                max_area = max(max_area, height * width);
            }
            st.push(i);
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

    vector<int> nums3 = {2, 1, 0, 2};
    cout << s.largestRectangleArea(nums3) << '\n'; // 2

    vector<int> nums4 = {5, 4, 1, 2};
    cout << s.largestRectangleArea(nums4) << '\n'; // 8
}
