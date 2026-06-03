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

            }

            st.push(i);
        }

        return response;
    }
};


int main() {
    auto s = Solution();

    vector<int> arr = {6, 2, 4};
    cout << s.mctFromLeafValues(arr) << endl; // 32
}
