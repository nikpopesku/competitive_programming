#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int mctFromLeafValues(const vector<int> &arr) {
        const int n = static_cast<int>(arr.size());
        stack<int> st;
        int response = 0;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                const int index = st.top();
                st.pop();
                const int product = !st.empty() ? arr[index] * arr[st.top()] : arr[index] * arr[i];
                response += product;
            }

            st.push(i);
        }

        while (!st.empty()) {
            const int index = st.top();
            st.pop();
            const int product = !st.empty() ? arr[index] * arr[st.top()] : 0;
            response += product;
        }

        return response;
    }
};


int main() {
    auto s = Solution();

    // vector<int> arr = {6, 2, 4};
    // cout << s.mctFromLeafValues(arr) << endl; // 32

    vector<int> arr2 = {4, 11};
    cout << s.mctFromLeafValues(arr2) << endl; // 44
}
