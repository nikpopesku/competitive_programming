#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (true) {
        cin >> n;

        if (n == 0) return 0;

        vector<int> rectangles(n);

        int max_area = 0;
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            cin >> rectangles[i];
        }

        for (int i = 0; i <= n; ++i) {
            int h = i == n ? 0 : rectangles[i];
            while (!st.empty() && rectangles[st.top()] >= h) {
                const int height = rectangles[i];
                st.pop();
                const int width = st.empty() ? i : i - st.top() - 1;
                max_area = max(max_area, width * height);
            }

            st.push(i);
        }

        cout << max_area << '\n';
    }
}
