#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string maskPII(string s) {
        if (const int at = get_at(s); at != -1) {
            string masked_string = to_string(tolower(s[0])) + "*****" + to_string(tolower(s[at - 1]));
            for (int i = at + 1; i < static_cast<int>(s.size()); ++i) {
                masked_string += to_string(tolower(s[i]));
            }

            return masked_string;
        }

        string masked_phone;
        int counter = 0;
        const int n = static_cast<int>(s.size());
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '(' || s[i] == ')' || s[i] == ' ') continue;
            masked_phone += counter++ < 4 ? s[i] : '*';
            if (counter == 4 || counter == 7) masked_phone += '-';
            if (counter == 10 && i < n - 1) masked_phone += '-';
        }

        if (counter > 10) masked_phone += '+';

        reverse(masked_phone.begin(), masked_phone.end());

        return masked_phone;
    }

private:
    int get_at(const string &s) {
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
    cout << s.maskPII("1(234)567-890") << '\n'; //"***-***-7890"
    cout << s.maskPII("10(234)567-890") << '\n'; //"***-***-7890"
    cout << s.maskPII("101(234)567-890") << '\n'; //"***-***-7890"
    cout << s.maskPII("1012(234)567-890") << '\n'; //"***-***-7890"
}
