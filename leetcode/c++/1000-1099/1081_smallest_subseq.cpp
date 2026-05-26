#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        string res;
        int last_occurrence[26] = {};
        bool in_stack[26] = {};

        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            last_occurrence[s[i] - 'a'] = i;
            in_stack[s[i] - 'a'] = false;
        }

        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            const int a = s[i] - 'a';
            if (in_stack[a]) continue;

            while (!res.empty() && res.back() > s[i] && last_occurrence[res.back() - 'a'] > i) {
                in_stack[res.back() - 'a'] = false;
                res.pop_back();
            }

            res.push_back(s[i]);
            in_stack[a] = true;
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
