#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int totalSteps(const vector<int> &nums) {
        int n;
        stack<int> st;
        vector<int> v = nums;
        int response = 0;

        do {
            n = static_cast<int>(v.size());
            for (int i = 0; i < n; ++i) {
                while (!st.empty() && v[st.top()] < v[i]) {
                    st.pop();
                }

                st.push(i);
            }

            if (n > static_cast<int>(v.size())) {
                ++response;
            }
        } while (n > static_cast<int>(v.size()));

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
