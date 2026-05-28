#include <iostream>
#include <stack>
#include <vector>

using namespace std;

constexpr int MODULO = 1e9 + 7;

class Solution {
public:
    int sumSubarrayMins(const vector<int> &arr) {
        const int n = static_cast<int>(arr.size());
        stack<int> st;
        vector left_count(n, 1);
        vector right_count(n, 1);

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                const int index = st.top();
                st.pop();

                right_count[index] = i - index;
                left_count[index] = st.empty() ? index + 1 : index - st.top();
            }
            st.push(i);
        }

        while (!st.empty()) {
            const int index = st.top();
            st.pop();

            right_count[index] = n - index;
            left_count[index] = st.empty() ? index + 1 : index - st.top();
        }

        long long response = 0;

        for (int i = 0; i < n; ++i) {
            response = (response + (static_cast<long long>(arr[i]) * left_count[i] % MODULO) * right_count[i] % MODULO) % MODULO;
        }

        return static_cast<int>(response);
    }
};

int main() {
    auto s = Solution();

    vector<int> arr = {3, 1, 2, 4};
    cout << s.sumSubarrayMins(arr) << endl; // Expected: 17

    vector<int> arr2 = {11, 81, 94, 43, 3};
    cout << s.sumSubarrayMins(arr2) << endl; // Expected: 444
}
