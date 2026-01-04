#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {

    }
};

int main() {
    Solution s;

    cout << s.removeDuplicateLetters("bcabc") << endl; //abc
    cout << s.removeDuplicateLetters("cbacdcbc") << endl; //acdb

    return 0;
}
