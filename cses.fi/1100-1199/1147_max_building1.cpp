#include<bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector forest(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> forest[i][j];
        }
    }

    int max_area = 0;
    vector<int> current_height(m + 1, 0);

    for (int i = 0; i < n; ++i) {
        stack<int> st;
        for (int j = 0; j <= m; ++j) {
            if (j == m || forest[i][j] == '*') {
                current_height[j] = 0;
            } else {
                ++current_height[j];
            }

            while (!st.empty() && current_height[st.top()] > current_height[j]) {
                st.pop();
                int height = current_height[j];
                int width = st.empty() ? j : j - st.top() - 1;

                max_area = max(max_area, width * height);
            }

            st.push(i);
        }

    }

    cout << max_area << '\n';
}
