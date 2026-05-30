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
            int counter = 0;
            while (!st.empty() && heights[st.top()] <= heights[i]) {
                ++counter;
                const int index = st.top();
                st.pop();
                response[index] += i - index;

                if (counter > 2) {
                    response[index] -= counter - 2;
                }
            }


            st.push(i);
        }
        int counter = 0;

        while (!st.empty()) {
            ++counter;
            const int index = st.top();
            st.pop();
            response[index] = n - index - 1;

            if (counter > 2) {
                response[index] -= counter - 2;
            }
        }

        return response;
    }
};

int main() {
    auto s = Solution();

    vector<int> heights = {10, 6, 8, 5, 11, 9};
    for (auto id: s.canSeePersonsCount(heights))
        cout << id << ' ';

    cout << '\n';

    vector<int> heights2 = {5, 1, 2, 3, 10};
    for (auto id: s.canSeePersonsCount(heights2))
        cout << id << ' ';

    cout << '\n';

    vector<int> heights3 = {4, 3, 2, 1};
    for (auto id: s.canSeePersonsCount(heights3))
        cout << id << ' ';
}
