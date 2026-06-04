#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int totalSteps(const vector<int> &nums) {
        stack<pair<int,int>> st; // (value, step)
        int response = 0;

        for (int num : nums) {
            int step = 0;
            while (!st.empty() && st.top().first <= num) {
                step = max(step, st.top().second);
                st.pop();
            }
            if (!st.empty()) step++;
            st.emplace(num, step);
            response = max(response, step);
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
