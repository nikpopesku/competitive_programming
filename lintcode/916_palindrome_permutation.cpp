#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param s: the given string
     * @return: if a permutation of the string could form a palindrome
     */
    bool canPermutePalindrome(string &s) {
        // write your code here
    }
};
int main() {
    Solution s;

    cout << s.canPermutePalindrome("code") << endl; //0
    cout << s.canPermutePalindrome("aab") << endl; //1
    cout << s.canPermutePalindrome("carerac") << endl; //1

    return 0;
}
