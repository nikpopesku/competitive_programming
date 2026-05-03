#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = static_cast<int>(temperatures.size());
        vector<int> answer(n, 0);
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                const int index = st.top();
                st.pop();
                answer[index] = i - index;
            }
            st.push(i);
        }

        return answer;
    }
};

int main() {
    auto s = Solution();

    for (vector<int> nums = {73, 74, 75, 71, 69, 72, 76, 73}; const auto e: s.dailyTemperatures(nums)) cout << e << ' ';
    cout << '\n';

    for (vector<int> nums = {30, 40, 50, 60}; const auto e: s.dailyTemperatures(nums)) cout << e << ' ';
    cout << '\n';

    for (vector<int> nums = {30, 60, 90}; const auto e: s.dailyTemperatures(nums)) cout << e << ' ';
    cout << '\n';

    for (vector<int> nums = {89, 62, 70, 58, 47, 47, 46, 76, 100, 70}; const auto e: s.dailyTemperatures(nums))
        cout << e << ' '; //[8,1,5,4,3,2,1,1,0,0]
    cout << '\n';
}
