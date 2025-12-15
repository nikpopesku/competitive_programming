#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(const string& s) {
        string result;
        result.reserve(s.size()); // Reserve memory to avoid reallocations
        int depth = 0;

        for (const char c : s) {
            if (c == '(') {
                if (depth++ > 0) { // Increment after check
                    result += c;
                }
            } else { // c == ')'
                if (--depth > 0) { // Decrement after check
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
