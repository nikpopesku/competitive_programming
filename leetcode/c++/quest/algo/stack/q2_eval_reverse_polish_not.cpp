#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
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
