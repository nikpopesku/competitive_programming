#include <iostream>
#include <unordered_map>


using namespace std;

class Solution {
public:
    int firstUniqChar(const string &s) {
        unordered_map<char, int> mp;

        for (auto &e: s) {
            ++mp[e];
        }

        int counter = 0;

        for (auto &e: s) {
            if (mp[e] == 1) {
                return counter;
            }

            ++counter;
        }

        return -1;
    }
};

int main() {
    auto s = Solution();
    cout << s.firstUniqChar("leetcode") << endl;
    cout << s.firstUniqChar("loveleetcode") << endl;
    cout << s.firstUniqChar("aabb") << endl;
}
