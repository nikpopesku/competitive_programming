#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string maskPII(string s) {
        if (const int at = get_at(s); at != -1) {
            string masked_string;
            masked_string += static_cast<char>(tolower(s[0]));
            masked_string += "*****";
            masked_string += static_cast<char>(tolower(s[at - 1]));
            masked_string += '@';
            for (int i = at + 1; i < static_cast<int>(s.size()); ++i) {
                masked_string += static_cast<char>(tolower(s[i]));
            }

            return masked_string;
        }

        string masked_phone;
        int counter = -1;
        string stripped_string;

        for (const auto &c: s) {
            if (c == '+' || c == '-' || c == '(' || c == ')' || c == ' ') continue;
            stripped_string += c;
        }

        for (int i = static_cast<int>(stripped_string.size()) - 1; i >= 0; --i) {
            ++counter;
            masked_phone += counter < 4 ? stripped_string[i] : '*';
            if (counter == 3 || counter == 6) masked_phone += '-';
            if (counter == 9 && i > 0) masked_phone += '-';
        }

        if (counter >= 10) masked_phone += '+';

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
    cout << s.maskPII("+46(427)55-7-41") << '\n'; //"***-***-5741"
}
