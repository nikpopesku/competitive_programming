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
            while (!st.empty() && rectangles[st.top()] >= rectangles[i]) {

            }

            st.push(i);
        }

        cout << max_area << '\n';
    }
}
