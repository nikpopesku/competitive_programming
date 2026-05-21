#include <string>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;


class Solution {
public:
    int maximalRectangle(const vector<vector<char> > &matrix) {
        int n = static_cast<int>(matrix.size());
        int m = static_cast<int>(matrix[0].size());
        int max_rectangle = 0;
        vector<int> current_height(m + 1, 0);

        for (int i = 0; i < n; ++i) {
            stack<int> st;

            for (int j = 0; j <= m; ++j) {
                if (j < m && matrix[i][j] == '1') {
                    ++current_height[j];
                } else {
                    current_height[j] = 0;
                }

                while (!st.empty() && current_height[st.top()] > current_height[j]) {
                    const int height = current_height[st.top()];
                    st.pop();
                    const int width = st.empty() ? j : j - st.top() - 1;
                    max_rectangle = max(max_rectangle, width * height);
                }

                st.push(j);
            }
        }


        return max_rectangle;
    }
};

int main() {
    auto s = Solution();

    vector<vector<char> > matrix = {
        {'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}
    };

    cout << s.maximalRectangle(matrix) << '\n';
}
