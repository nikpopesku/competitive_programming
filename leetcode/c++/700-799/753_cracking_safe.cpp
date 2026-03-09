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
        unordered_map<string, int> nxt;

        while (!st.empty()) {
            if (string node = st.top(); nxt[node] >= 0) {          // still has digits left
                const char d = '0' + nxt[node]--;
                st.push(node.substr(1) + d);
            } else {
                st.pop();
                path += node.back();       // collect last char (the "new" digit)
            }
        }

        reverse(path.begin(), path.end());
        return s + path;   // s is your initial "00...0"

    }
};

int main() {
    auto s = Solution();

    cout << s.crackSafe(1, 2) << '\n'; //10
    cout << s.crackSafe(2, 2) << '\n'; //01100
}
