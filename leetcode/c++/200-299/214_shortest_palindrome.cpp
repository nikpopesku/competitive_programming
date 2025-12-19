#include <iostream>
#include <ranges>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string shortestPalindrome(const string &s) {
        unordered_map<char, int> mp;
        for (auto &c: s) {
            ++mp[c];
        }

        int odd = 0;

        for (const auto &val: mp | views::values) {
            if (val % 2 == 1) {
                ++odd;
            }
        }

        string response;

        for (int i = static_cast<int>(s.size()) - 1; i >= s.size() - odd + 1; ++i) {
            response += s[i];
        }

        return response + s;
    }
};

int main() {
    Solution s;

    cout << s.shortestPalindrome("aacecaaa") << endl; //aaacecaaa
    cout << s.shortestPalindrome("abcd") << endl; //dcbabcd

    return 0;
}
