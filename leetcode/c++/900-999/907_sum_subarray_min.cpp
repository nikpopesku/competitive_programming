#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(const vector<int> &arr) {
        const int n = static_cast<int>(arr.size());
        stack<int> st;
        vector<int> left_count(n, 1);
        vector<int> right_count(n, 1);

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                int index = st.top();
                st.pop();

                right_count[index] = i - index;
            }
            st.push(i);
        }
    }
};

int main() {
    auto s = Solution();

    vector<int> arr = {3, 1, 2, 4};
    cout << s.sumSubarrayMins(arr) << endl; // Expected: 17

    vector<int> arr2 = {11, 81, 94, 43, 3};
    cout << s.sumSubarrayMins(arr2) << endl; // Expected: 444
}
