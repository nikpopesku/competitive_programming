#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;

        for (auto & c: s) {
            ++mp[c];
        }

        int response = 0;
        bool has_odd = false;

        for (auto &e : mp) {
            if (!has_odd && e.second % 2 == 1) {
                has_odd = true;
            }

            response += e.second % 2 == 1 ? e.second - 1: e.second;
        }

        if (has_odd) {
            ++response;
        }

        return response;
    }
};

int main() {
    Solution s;

    cout << s.longestPalindrome("abccccdd") << endl;
    cout << s.longestPalindrome("a") << endl;

    return 0;
}
