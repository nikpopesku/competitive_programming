#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(const string &s) {
        int left = 0, right = static_cast<int>(s.size() - 1);

        while (left <= right) {
            int cl = tolower(s[left]), cr = tolower(s[right]);
            if (cl > 'z' || cl < 'a') {
                ++left;
                continue;
            }

            if (cr > 'z' || cr < 'a') {
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

    return 0;
}
