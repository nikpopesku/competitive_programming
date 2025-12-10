#include <ranges>
#include <unordered_map>

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
