#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(const string &s) {
        if (s.empty()) return 0;
        vector v(256, false);

        const int n = static_cast<int>(s.size());
        int left = 0, right = 0;
        int max_length = 0;

        while (right < n) {
            while (v[s[right]]) {
                ++left;
                v[s[left - 1]] = false;
            }

            max_length = max(max_length, right - left + 1);
            v[s[right]] = true;
            ++right;
        }

        return max_length;
    }
};

int main() {
    auto s = Solution();

    const string ss = "abcabcbb";
    cout << s.lengthOfLongestSubstring(ss) << '\n';

    const string ss2 = "bbbbb";
    cout << s.lengthOfLongestSubstring(ss2) << '\n';

    const string ss3 = "pwwkew";
    cout << s.lengthOfLongestSubstring(ss3) << '\n';

}
