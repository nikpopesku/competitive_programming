#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string crackSafe(int n, int k) {
        if (n == 1) {
            string res;
            for (int i = 0; i < k; ++i) res += ('0' + i);
            return res;
        }

        const string s(n - 1, '0');
        stack<string> st;
        st.push(s);
        string path;
        unordered_map<string, int> nxt;

        while (!st.empty()) {
            string node = st.top();
            if (!nxt.contains(node)) nxt[node] = k - 1; // first visit: try k-1 down to 0
            if (nxt[node] >= 0) {
                const char d = '0' + nxt[node]--;
                st.push(node.substr(1) + d);
            } else {
                st.pop();
                path += node.back(); // collect the digit this node added
            }
        }

        reverse(path.begin(), path.end());
        // reversed path already begins with the initial "00..0" window's last char;
        // prepend the first n-2 chars of the prefix to complete it
        return s.substr(0, n - 2) + path;
    }
};

int main() {
    auto s = Solution();

    cout << s.crackSafe(1, 2) << '\n'; //10
    cout << s.crackSafe(2, 2) << '\n'; //01100
}
