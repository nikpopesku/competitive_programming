#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;

        for (string &t: tokens) {
            if (t != "+" && t != "-" && t != "*" && t != "/") {
                st.push(stoi(t));
            } else {
                const int op2 = st.top();
                st.pop();
                const int op1 = st.top();
                st.pop();

                if (t == "+") st.push(op1 + op2);
                if (t == "-") st.push(op1 - op2);
                if (t == "*") st.push(op1 * op2);
                if (t == "/") st.push(op1 / op2);
            }
        }

        return st.top();
    }
};

int main() {
    auto s = Solution();

    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    cout << s.evalRPN(tokens1) << '\n';

    vector<string> tokens2 = {"2", "1", "+", "3", "*"};
    cout << s.evalRPN(tokens2) << '\n';

    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << s.evalRPN(tokens3) << '\n';
}
