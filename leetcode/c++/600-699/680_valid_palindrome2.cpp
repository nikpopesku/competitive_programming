#include <iostream>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = static_cast<int>(s.size()) - 1;

        while (left < right) {
            if (s[left] == s[right]) {
                ++left;
                --right;
            } else {
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
        }

        return true;
    }

private:
    static bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};

int main() {
    Solution s;

    cout << s.validPalindrome("aba") << endl;
    cout << s.validPalindrome("abca") << endl;
    cout << s.validPalindrome("abc") << endl;
    cout << s.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga") << endl;

    return 0;
}
