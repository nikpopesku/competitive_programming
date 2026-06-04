#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int totalSteps(vector<int> &nums) {
        stack<int> st;
        int n = static_cast<int>(nums.size());
        int response = 0;
        bool flag = true;

        while (flag) {
            flag = false;
            for (int i = 0; i < n; ++i) {
                while (!st.empty() && nums[st.top()] < nums[i]) {
                    if (!flag) {
                        ++response;
                        flag = true;
                    }
                    int index = st.top();
                    st.pop();

                }

                st.push(i);
            }
        }

        return response;
    }
};


int main() {
    auto s = Solution();

    vector<int> arr = {5, 3, 4, 4, 7, 3, 6, 11, 8, 5, 11};
    cout << s.totalSteps(arr) << endl; // 3

    vector<int> arr2 = {4, 5, 7, 7, 13};
    cout << s.totalSteps(arr2) << endl; // 0
}
