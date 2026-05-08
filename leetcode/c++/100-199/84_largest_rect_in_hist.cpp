#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int max_area = 0;
        int n = static_cast<int>(heights.size());
        stack<int> st;

        for (int i = 0; i <= n; ++i) {
            int h = i < n ? heights[i] : 0;
            while (!st.empty() && heights[st.top()] > heights[i]) {
                st.pop();
            }

            int height = heights[st.top()];
            int width = st.empty() ? i + 1 : i - st.top() - 1;
            max_area = max(max_area, height * width);
            st.push(i);
        }

        return max_area;
    }
};


int main() {
    auto s = Solution();

    vector nums = {9, 3, 15, 20, 7};
    cout << s.largestRectangleArea(nums) << endl;

    vector nums2 = {2, 4};
    cout << s.largestRectangleArea(nums2) << endl;
}
