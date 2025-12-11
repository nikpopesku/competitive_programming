#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(const string &s) {
        int left = 0, right = static_cast<int>(s.size() - 1);

        while (left <= right) {
            if (s[left] > 'z' || s[left] > 'Z' || s[left] < 'a' || s[left] < 'A') {
                ++left;
                continue;
            }

            if (s[right] > 'z' || s[right] > 'Z' || s[right] < 'a' || s[right] < 'A') {
                --right;
                continue;
            }

            if (tolower(s[left]) != tolower(s[right])) {
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

    return 0;
}
