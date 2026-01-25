#include <algorithm>
#include <complex>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;

        for (auto& c: s) {
            if (st.empty()) {
                st.push({c, 1});

                continue;
            }

            if (st.top().first == c) {
                auto [fst, snd] = st.top();
                st.pop();

                if (snd + 1 < k) {
                    st.push({fst, snd + 1});
                }
            }
        }
    }
};

int main() {
    Solution s;

    cout << s.removeDuplicates("abcd", 2) << endl; //abcd
    cout << s.removeDuplicates("deeedbbcccbdaa", 3) << endl; //aa
    cout << s.removeDuplicates("pbbcggttciiippooaais", 2) << endl; //ps

    return 0;
}
