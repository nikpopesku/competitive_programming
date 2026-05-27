#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string s;
    cin >> s;
    const int n = static_cast<int>(s.size());

    string u;

    stack<int> st;
    vector<int> v(n + 1, 'z' + 1);

    for (int i = n - 1; i >= 0; --i)
        v[i] = min(static_cast<int>(s[i]), v[i + 1]);

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && s[st.top()] <= v[i]) {
            u += s[st.top()];
            st.pop();
        }

        st.push(i);
    }

    while (!st.empty()) {
        u += s[st.top()];
        st.pop();
    }

    cout << u;
}
