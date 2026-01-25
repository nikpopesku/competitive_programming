#include <iostream>
#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param s: the given string
     * @return: if a permutation of the string could form a palindrome
     */
    bool canPermutePalindrome(const string &s) {
        unordered_map<char, int> mp;

        for (auto c: s) {
            ++mp[c];
        }

        int counter = 0;

        for (const auto val: mp) {
            if (val.second % 2 == 1) {
                ++counter;
                if (counter > 1) {
                    break;
                }
            }
        }

        return counter <= 1;
    }
};
int main() {
    Solution s;

    cout << s.canPermutePalindrome("code") << endl; //0
    cout << s.canPermutePalindrome("aab") << endl; //1
    cout << s.canPermutePalindrome("carerac") << endl; //1

    return 0;
}
