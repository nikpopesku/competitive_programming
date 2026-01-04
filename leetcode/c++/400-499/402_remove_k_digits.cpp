#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeKdigits(const string &num, int k) {
        vector<char> st;

        for (const auto &c: num) {
            if (k > 0 && !st.empty() && st[st.size() - 1] > c) {
                st.pop_back();
                --k;
            }

            if (st.empty() && c == '0') {
                continue;
            }

            st.push_back(c);
        }

        while (k && !st.empty()) {
            st.pop_back();
            --k;
        }

        string s(st.begin(), st.end());

        return !s.empty() ? s : "0";
    }
};

int main() {
    Solution s;

    // cout << s.removeKdigits("1432219", 3) << endl; //1219
    // cout << s.removeKdigits("10200", 1) << endl; //200
    // cout << s.removeKdigits("10", 2) << endl; //0
    // cout << s.removeKdigits("9", 1) << endl; //0
    cout << s.removeKdigits("33526221184202197273", 19) << endl; //0

    return 0;
}
