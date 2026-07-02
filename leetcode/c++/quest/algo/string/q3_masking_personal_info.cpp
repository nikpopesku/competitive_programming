#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string maskPII(string s) {
        if (const int at = get_at(s); at != -1) {
            string masked_string = tolower(s[0]) + "*****" + tolower(s[at - 1]);
            for (int i = at + 1; i < static_cast<int>(s.size()); ++i) {
                masked_string += tolower(s[i]);
            }

            return masked_string;
        }

        string masked_phone;
        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '(' || s[i] == ')' || s[i] == ' ') continue;


        }

        return masked_phone;
    }

private:
    int get_at(string &s) {
        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            if (s[i] == '@') return i;
        }

        return -1;
    }
};


int main() {
    auto s = Solution();
    cout << s.maskPII("LeetCode@LeetCode.com") << '\n'; //"l*****e@leetcode.com"
    cout << s.maskPII("AB@qq.com") << '\n'; //"a*****b@qq.com"
}
