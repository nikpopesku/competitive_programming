#include <iostream>
#include <ranges>
#include <unordered_map>
#include <vector>


using namespace std;

class Solution {
public:
    int longestPalindrome(const string& s) {
        unordered_map<char, int> mp;

        for (auto &c: s) {
            ++mp[c];
        }

        int response = 0;
        bool has_odd = false;

        for (auto &val: mp | views::values) {
            if (!has_odd && val % 2 == 1) {
                has_odd = true;
            }

            response += val % 2 == 1 ? val - 1 : val;
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
