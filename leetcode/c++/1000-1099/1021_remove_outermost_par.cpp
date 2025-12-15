#include <iostream>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {

    }
};

int main() {
    Solution s;

    cout << s.removeOuterParentheses("(()())(())") << endl;
    cout << s.removeOuterParentheses("(()())(())(()(()))") << endl;
    cout << s.removeOuterParentheses("()()") << endl;

    return 0;
}
