#include <iostream>
#include <unordered_map>


using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size()) {
            return false;
        }

        unordered_map<char, int> mp;
        int odd = 0;

        for (auto &c: s) {
            ++mp[c];

            if (mp[c] % 2 == 1) {
                ++odd;
            } else {
                --odd;
            }
        }

        if (odd > k) {
            return false;
        }

        return true;
    }
};

int main() {
    Solution s;

    cout << s.canConstruct("annabelle", 2) << endl;
    cout << s.canConstruct("leetcode", 3) << endl;
    cout << s.canConstruct("true", 4) << endl;

    return 0;
}
