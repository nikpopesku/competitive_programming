#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(const string &s) {
        string result;
        result.reserve(s.size());
        int depth = 0;

        for (auto &c: s) {
            if (c == '(') {
                if (++depth > 1) {
                    result += c;
                }
            } else {
                if (--depth > 0) {
                    result += c;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution s;

    cout << s.removeOuterParentheses("(()())(())") << endl;
    cout << s.removeOuterParentheses("(()())(())(()(()))") << endl;
    cout << s.removeOuterParentheses("()()") << endl;

    return 0;
}
