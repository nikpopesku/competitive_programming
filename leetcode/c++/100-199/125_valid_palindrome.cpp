#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(const string &s) {
        int left = 0, right = static_cast<int>(s.size() - 1);

        while (left <= right) {
            const int cl = tolower(s[left]);
            const int cr = tolower(s[right]);

            if ((cl > 'z' || cl < 'a') && (cl > '9' || cl < '0')) {
                ++left;
                continue;
            }

            if ((cr > 'z' || cr < 'a') && (cr > '9' || cr < '0')) {
                --right;
                continue;
            }

            if (cr != cl) {
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

    cout << s.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << s.isPalindrome("race a car") << endl;
    cout << s.isPalindrome(" ") << endl;
    cout << s.isPalindrome("0P") << endl;

    return 0;
}
