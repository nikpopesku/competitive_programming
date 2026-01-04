#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<char> v;
        unordered_map<char, vector<int> > mp;
        set<char> st;
        const size_t n = s.size();

        for (int i = 0; i < n; ++i) {
            mp[s[i]].push_back(i);
        }

        for (int i = 0; i < n; ++i) {
            if (st.contains(s[i])) {
                continue;
            }

            while (!v.empty() && s[i] < v.back() && mp[v.back()].back() > i) {
                st.erase(v.back());
                v.pop_back();
            }

            v.push_back(s[i]);
            st.insert(s[i]);
        }

        string ss(v.begin(), v.end());

        return ss;
    }
};

int main() {
    Solution s;

    cout << s.removeDuplicateLetters("bcabc") << endl; //abc
    cout << s.removeDuplicateLetters("cbacdcbc") << endl; //acdb

    return 0;
}
