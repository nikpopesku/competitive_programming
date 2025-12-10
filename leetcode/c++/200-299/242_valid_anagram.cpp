#include <ranges>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(const string& s, const string& t) {
        unordered_map<int, int> mp;

        for (auto &c: s) {
            ++mp[c - 'a'];
        }

        for (const auto &c: t) {
            if (mp[c - 'a'] == 0) {
                return false;
            }

            --mp[c - 'a'];
        }

        for (const auto &val: mp | views::values) {
            if (val > 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    auto s = Solution();
    cout << s.isAnagram("anagram", "nagaram") << endl;
    cout << s.isAnagram("rat", "car") << endl;
}
