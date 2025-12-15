#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicates(const string &s) {
        vector<int> st;

        for (const auto &c: s) {
            bool popped = false;
            while (!st.empty()) {
                if (st[st.size() - 1] == c) {
                    st.pop_back();
                    popped = true;
                } else {
                    break;
                }
            }

            if (!popped) {
                st.push_back(c);
            }
        }

        string t(st.begin(), st.end());

        return t;
    }
};

int main() {
    Solution s;

    cout << s.removeDuplicates("abbaca") << endl;
    cout << s.removeDuplicates("azxxzy") << endl;
    cout << s.removeDuplicates("aabbaca") << endl;

    return 0;
}
