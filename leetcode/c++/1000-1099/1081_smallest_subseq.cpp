#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        int last[26] = {};
        bool in_stack[26] = {};
        string res;

        for (int i = 0; i < static_cast<int>(s.size()); ++i)
            last[s[i] - 'a'] = i;

        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            const int c = s[i] - 'a';
            if (in_stack[c]) continue;

            while (!res.empty() && res.back() > s[i] && last[res.back() - 'a'] > i) {
                in_stack[res.back() - 'a'] = false;
                res.pop_back();
            }
            in_stack[c] = true;
            res.push_back(s[i]);
        }

        return res;
    }
};

int main() {
    Solution s;

    cout << s.smallestSubsequence("bcabc") << endl; //abc
    cout << s.smallestSubsequence("cbacdcbc") << endl; //acdb

    return 0;
}
