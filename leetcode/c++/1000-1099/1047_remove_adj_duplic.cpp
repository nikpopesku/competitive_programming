#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> st;

        for (auto &c: s) {
            while (!st.empty()) {
                if (st.top() == c) {
                    st.pop();
                }
            }
        }
    }
};

int main() {
    Solution s;

    cout << s.removeDuplicates("abbaca") << endl;
    cout << s.removeDuplicates("azxxzy") << endl;
    cout << s.removeDuplicates("aabbaca") << endl;

    return 0;
}
