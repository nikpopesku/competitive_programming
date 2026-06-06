#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

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
