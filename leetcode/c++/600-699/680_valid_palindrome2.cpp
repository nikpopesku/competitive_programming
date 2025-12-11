#include <iostream>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = static_cast<int>(s.size()) - 1;
        int counter = 0;

        while (left <= right && counter <= 1) {
            if (s[left] != s[right]) {
                if (s[left + 1] == s[right]) {
                    ++left;
                } else {
                    --right;
                }

                ++counter;
            }
        }

        return counter <= 1;
    }
};

int main() {
    Solution s;

    cout << s.validPalindrome("aba") << endl;
    cout << s.validPalindrome("abca") << endl;
    cout << s.validPalindrome("abc") << endl;

    return 0;
}
