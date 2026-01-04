#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<char> v;
        unordered_map<char, vector<int> > mp;
        const size_t n = s.size();

        for (int i = 0; i < n; ++i) {
            mp[s[i]].push_back(i);
        }

        for (int i = 0; i < n; ++i) {
            if (v.empty()) {
                v.push_back(s[i]);
                continue;
            }
            auto occ = mp[v[v.size() - 1]];
            while (s[i] < v[v.size() - 1] && occ[occ.size() - 1] > i) {
                v.pop_back();
                occ = mp[v[v.size() - 1]];
            }
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
