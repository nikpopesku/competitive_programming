#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(const string &s) {
        if (s.empty()) return 0;
        vector v(26, false);

        const int n = static_cast<int>(s.size());
        int left = 0, right = 0;
        int max_length = 0;

        while (right < n) {
            while (v[s[right] - 'a']) {
                ++left;
                v[s[left - 1] - 'a'] = false;
            }

            max_length = max(max_length, right - left + 1);
            v[s[right] - 'a'] = true;
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
