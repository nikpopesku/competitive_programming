#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string crackSafe(int n, int k) {
        stack<string> st;
        string s;
        for (int i = 0; i < n - 1; ++i) s += '0';
        st.push(s);
        string path;

        while (!st.empty()) {
            string node = st.top();

            if (!node.empty()) {
                auto d = next_digit(node);
                next = node.substr(1) + d;      // slide window
                st.push(next);
            } else {
                st.pop();
                path += node;             // dead end → collect it
            }
        }

        return path;
    }
};

int main() {
    auto s = Solution();

    cout << s.crackSafe(1, 2) << '\n'; //10
    cout << s.crackSafe(2, 2) << '\n'; //01100
}
