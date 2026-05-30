#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(const vector<int> &heights) {
        stack<int> st;
        const int n = static_cast<int>(heights.size());
        vector response(n, 0);

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                const int index = st.top();
                st.pop();
                response[index] = st.empty() ? i - 1 : i - st.top();
            }

            st.push(i);
        }

        return response;
    }
};

int main() {
    auto s = Solution();

    vector<int> heights = {10, 6, 8, 5, 11, 9};
    for (auto id: s.canSeePersonsCount(heights))
        cout << id << endl;

    vector<int> heights2 = {5, 1, 2, 3, 10};
    for (auto id: s.canSeePersonsCount(heights2))
        cout << id << endl;
}
