#include <iostream>
#include <stack>
#include <vector>

using namespace std;


class Solution {
public:
    int trap(const vector<int>& height) {
        stack<int> st;
        const int n = static_cast<int>(height.size());
        int response = 0;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && height[st.top()] < height[i]) {
                const int index = st.top();
                st.pop();

                response += !st.empty() ? height[i] - height[index] : 0;
            }
            st.push(i);
        }

        return response;
    }
};


int main() {
    auto s = Solution();

    vector nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << s.trap(nums) << endl; //6

    vector nums2 = {4, 2, 0, 3, 2, 5};
    cout << s.trap(nums2) << endl;
}
