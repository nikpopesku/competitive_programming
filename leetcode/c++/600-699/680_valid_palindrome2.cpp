#include <iostream>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {

    }
};

int main() {
    Solution s;

    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << s.isPalindrome("race a car") << endl;
    cout << s.isPalindrome(" ") << endl;
    cout << s.isPalindrome("0P") << endl;

    return 0;
}
